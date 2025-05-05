//
// Created by jake.otte on 5/5/2025.
//

#ifndef TEAMSERVERWINDOW_H
#define TEAMSERVERWINDOW_H

#include <QMainWindow>
#include <vector>

#include "../include/types.h"

#include "listenersdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TeamserverWindow; }
QT_END_NAMESPACE

class TeamserverWindow : public QMainWindow {
Q_OBJECT

public:
    explicit TeamserverWindow(QWidget *parent = nullptr);
    ~TeamserverWindow() override;
    void refresh_listeners();

    Ui::TeamserverWindow *ui;
    std::vector<Listener> g_Listeners;
    std::vector<Agent> g_Agents;

private slots:
    void on_createListenerButton_clicked();


private:
    ListenersDialog *ui_listeners;
};


#endif //TEAMSERVERWINDOW_H
