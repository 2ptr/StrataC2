//
// Created by jake.otte on 5/5/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TeamserverWindow.h" resolved

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

TeamserverWindow::~TeamserverWindow() {
    delete ui;
}
