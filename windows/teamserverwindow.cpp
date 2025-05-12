#include <string>
#include <chrono>
#include <iomanip>
#include <QTimer>

#include "teamserverwindow.h"
#include "ui_TeamserverWindow.h"
#include "../classes/Constants.h"


TeamserverWindow::TeamserverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeamserverWindow) {
    ui->setupUi(this);

    // Bind tables to self-reference
    ui->agentTable->setMainWindow(this);
    ui->listenersTable->setMainWindow(this);
    ui->cmdsTextEdit->setMainWindow(this);

    // Dynamic resizes
    ui->agentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->listenersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // UI windows
    ui_listeners = new ListenersDialog(this, this);

    // Last live timer
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TeamserverWindow::update_last_alive);
    timer->start(1000);  // Trigger every 1000 ms (1 second)

    // Signals
    connect(this, &TeamserverWindow::agentUpdated, this, &TeamserverWindow::on_agentTable_itemSelectionChanged);

    this->showMaximized();
}

// SLOTS
void TeamserverWindow::on_createListenerButton_clicked() {
    ui_listeners->show();
}

void TeamserverWindow::on_agentTable_itemClicked() {
    ui->cmdsTextEdit->repopulateItems();
}

void TeamserverWindow::on_agentTable_itemSelectionChanged() {
    ui->cmdsTextEdit->repopulateItems();
}

void TeamserverWindow::on_commandLine_returnPressed() {
    // Get the selected agent
    AgentTableWidgetItem* selected_item = ui->agentTable->selectedItem();
    if (selected_item == nullptr) {
        return;  // No item selected, exit early
    }
    std::string selected_id = selected_item->data->id;
    std::string cmd = ui->commandLine->text().toStdString();
    ui->commandLine->clear();

    std::istringstream iss(cmd);
    std::string word;

    // Split into words
    std::vector<std::string> tokens;
    while (iss >> word) {
        tokens.push_back(word);
    }

    std::map<std::string, std::vector<std::string>> cmd_entry;
    // Extract command and args
    if (!tokens.empty()) {
        std::string command = tokens[0];
        std::vector<std::string> args(tokens.begin() + 1, tokens.end());

        // Example: build a map for cmd_queue
        cmd_entry[command] = args;
    }

    // Find the actual agent in g_Agents and update it
    for (Agent& agent : g_Agents) {
        if (agent.id == selected_id) {
            agent.cmd_history.push_back(">>> " + cmd);
            agent.cmd_history.push_back(MSG_COMMAND_QUEUED);
            agent.cmd_queue.push_back(cmd_entry);
            break;
        }
    }

    // Update UI
    ui->cmdsTextEdit->repopulateItems();
}

void TeamserverWindow::update_last_alive() {
    // Loop through the agents and update the table
    for (int i = 0; i < g_Agents.size(); ++i) {
        Agent& agent = g_Agents[i];
        agent.last_alive += 1;

        // Update only the relevant cell in the table (column 5 for last_alive)
        QTableWidgetItem* item = ui->agentTable->item(i, 5);
        if (item) {
            item->setText(QString::number(agent.last_alive));
        }
    }
}

void TeamserverWindow::log_activity(std::string msg) {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm;
    localtime_s(&tm, &t);  // Use localtime_r for POSIX

    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");

    std::string final = "[" + oss.str() + "] : " + msg;
    ui->activityList->insertItem(0, QString::fromStdString(final));
}

TeamserverWindow::~TeamserverWindow() {
    delete ui;
}
