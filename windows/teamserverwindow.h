#ifndef STRATAC2_TEAMSERVERWINDOW_H
#define STRATAC2_TEAMSERVERWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

#include "../include/types.h"
#include "listenersdialog.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class TeamserverWindow;
}

QT_END_NAMESPACE

class TeamserverWindow : public QMainWindow {
    Q_OBJECT

public:
    Ui::TeamserverWindow *ui;
    ListenersDialog *ui_listeners;
    std::vector<Listener> g_Listeners;
    std::vector<Agent> g_Agents;

    void refresh_listeners();
    void log_activity(std::string msg);

    explicit TeamserverWindow(QWidget *parent = nullptr);
    ~TeamserverWindow() override;

private slots:
    void on_createListenerButton_clicked();
};

#endif //STRATAC2_TEAMSERVERWINDOW_H
