#include "Listeners.h"

#include "../windows/ui_TeamserverWindow.h"

#include "Agents.h"
#include "../windows/teamserverwindow.h"

void HTTPListenerThread::run() {

    svr.set_post_routing_handler([this](const httplib::Request &req, httplib::Response &res) {
    printf("Received POST to: %s\n", req.path.c_str());
    try {
        // Parse the JSON data from the request body
        auto json_data = nlohmann::json::parse(req.body);

        // Convert the JSON to a CallbackFull object
        CallbackFull full = CallbackFull::from_json(json_data);

        // Does the Agent already exist?
        auto it = std::ranges::find_if(main_window->g_Agents,
                                       [&full](const Agent& a) { return a.id == full.metadata.id; });

        if (it == main_window->g_Agents.end()) {
            // Agent not found – add new
            Agent new_agent(full.metadata.id,
                            full.metadata.hostname,
                            full.metadata.user,
                            full.metadata.process,
                            full.metadata.ip);
            new_agent.cmd_history.push_back("[*] Agent connected - " + full.metadata.id);
            main_window->g_Agents.push_back(new_agent);
            main_window->log_activity("New Agent connected - " + full.metadata.id);
        } else {
            // Agent exists – reset last_alive
            it->last_alive = 0;
        }
        main_window->ui->agentTable->repopulateItems();

        // Respond with a JSON message
        nlohmann::json response_data;
        response_data["status"] = "ok";
        response_data["message"] = "Lovely";

        // Set the response content and type
        res.set_content(response_data.dump(), "application/json");
        res.status = 200;

    } catch (const std::exception& e) {
        // If there is a parsing error, respond with an error
        res.status = 400;
        res.set_content("{\"status\":\"error\",\"message\":\"Invalid JSON\"}", "application/json");
    }

    return httplib::Server::HandlerResponse::Handled;
});

    // Start the server
    svr.listen_after_bind();
}