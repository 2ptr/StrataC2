//
// Created by jake.otte on 5/12/2025.
//

#include "CommandHelper.h"

#include "Constants.h"
#include "../windows/ui_TeamserverWindow.h"
#include "../components/TableWidgets.h"

void CommandHelper::handle_command() {
    // Retrieve the selected agent
    AgentTableWidgetItem* selected_item = mainWindow->ui->agentTable->selectedItem();
    if (selected_item == nullptr) {
        return;  // No item selected, exit early
    }
    std::string selected_id = selected_item->data->id;
    Agent* selected_agent = nullptr;
    // Find the actual agent in g_Agents and update it
    for (Agent& agent : mainWindow->g_Agents) {
        if (agent.id == selected_id) {
            selected_agent = &agent;
            break;
        }
    }
    if (selected_agent == nullptr) {
        return;
    }

    // Retrieve input / ux
    std::string user_input = mainWindow->ui->commandLine->text().toStdString();
    selected_agent->cmd_history.push_back(">>> " + user_input);
    mainWindow->ui->commandLine->clear();
    // Split into words
    std::istringstream iss(user_input);
    std::string word;
    std::vector<std::string> tokens;
    while (iss >> word) {
        tokens.push_back(word);
    }
    // Extract command and args
    std::string command;
    std::vector<std::string> args;
    std::map<std::string, std::vector<std::string>> cmd_entry;
    if (!tokens.empty()) {
        command = tokens[0];
        args = std::vector(tokens.begin() + 1, tokens.end());
        cmd_entry[command] = args;
    }

    // PREPROCESSING AND ISSUING FOR COMMANDS
    if (command == "help") {
        selected_agent->cmd_history.push_back(CMD_HELP);
    } else {;
        selected_agent->cmd_queue.push_back(cmd_entry);
        selected_agent->cmd_history.push_back(MSG_COMMAND_QUEUED);
    }

    // Update UI
    mainWindow->ui->cmdsTextEdit->repopulateItems();
}
