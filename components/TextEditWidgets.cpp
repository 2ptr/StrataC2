#include "texteditwidgets.h"
#include "../windows/teamserverwindow.h"
#include "../windows/ui_TeamserverWindow.h"
#include "TableWidgets.h"
#include "../classes/Constants.h"

CommandsTextEdit::CommandsTextEdit(QWidget *parent) : QTextEdit(parent) {
    this->setReadOnly(true);
}

void CommandsTextEdit::setMainWindow(TeamserverWindow* main_window) {
    mainWindow = main_window;
}

void CommandsTextEdit::repopulateItems() {
    setText("");
    // First, check if selectedItem() is nullptr
    AgentTableWidgetItem *selected_item = mainWindow->ui->agentTable->selectedItem();
    if (selected_item == nullptr) {
        return;  // No item selected, exit early
    }

    std::string selected_id = selected_item->data->id;
    mainWindow->ui->agentLabel->setText(QString::fromStdString("Agent: " + selected_id));

    // Find the actual agent in g_Agents and read from it
    for (Agent& agent : mainWindow->g_Agents) {
        if (agent.id == selected_id) {
            // Now safely access the agent's cmd_history
            for (const std::string& cmd : agent.cmd_history) {
                append(QString::fromStdString(format_command(cmd)));
            }
            break;
        }
    }
}

std::string CommandsTextEdit::format_command(std::string command) {
    if (command == MSG_COMMAND_QUEUED) {
        command = "<font color='gray'>" + command + "</font>\n";
    } else if (command == MSG_OUTPUT_RECEIVED) {
        command = "<font color='#12AD2B'>" + command + "</font>\n";
    } else if (command == MSG_COMMAND_SENT) {
        command = "<font color='yellow'>" + command + "</font>\n";
    } else {
        command += "\n";
    }
    return command;
}