#include <string>
#include <chrono>
#include <iomanip>

#include "teamserverwindow.h"
#include "ui_TeamserverWindow.h"


TeamserverWindow::TeamserverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeamserverWindow) {
    ui->setupUi(this);

    // Bind tables to self-reference
    ui->agentTable->setMainWindow(this);
    ui->listenersTable->setMainWindow(this);

    // Dynamic resizes
    ui->agentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->listenersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // UI windows
    ui_listeners = new ListenersDialog(this, this);

    this->show();
}

// SLOTS
void TeamserverWindow::on_createListenerButton_clicked() {
    ui_listeners->show();
}

void TeamserverWindow::log_activity(std::string msg) {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm;
    localtime_s(&tm, &t);  // Use localtime_r for POSIX

    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");

    std::string final = "[" + oss.str() + "] : " + msg;
    ui->activityList->addItem(QString::fromStdString(final));
}

TeamserverWindow::~TeamserverWindow() {
    delete ui;
}
