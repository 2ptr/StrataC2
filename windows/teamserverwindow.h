#ifndef STRATAC2_TEAMSERVERWINDOW_H
#define STRATAC2_TEAMSERVERWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

#include "../classes/Agents.h"
#include "../classes/Listeners.h"
#include "listenersdialog.h"
#include "payloadsdialog.h"
#include "../classes/CommandHelper.h"

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
    PayloadsDialog *ui_payloads;
    std::vector<Listener> g_Listeners;
    std::vector<Agent> g_Agents;
    CommandHelper *commandHelper;

    void refresh_listeners();
    void log_activity(std::string msg);

    explicit TeamserverWindow(QWidget *parent = nullptr);
    ~TeamserverWindow() override;
signals:
    void agentUpdated();
private slots:
    void on_createListenerButton_clicked();

    void on_actionGenerate_triggered();

    void on_agentTable_itemClicked();

    void on_agentTable_itemSelectionChanged();

    void on_commandLine_returnPressed();

    void update_last_alive();
};

#endif //STRATAC2_TEAMSERVERWINDOW_H
