#pragma once
#include <QString>
#include <QWidget>
#include <QHeaderView>
#include <QTableWidgetItem>
#include "../classes/Agents.h"

#include "../windows/teamserverwindow.h"

// Forward declarations for the specific Table Widget Item types
class Listener;
class Agent;
class TeamserverWindow;

// Base Table Widget Item class
template <typename T>
class BaseTableWidgetItem : public QTableWidgetItem {
public:
    T* data;

    BaseTableWidgetItem(T* data, const QString& text) : QTableWidgetItem(text), data(data) {}
};

// Agent Table Widget Item
class AgentTableWidgetItem : public BaseTableWidgetItem<Agent> {
public:
    AgentTableWidgetItem(Agent* agent, const QString& text)
        : BaseTableWidgetItem(agent, text) {}
};

// Listener Table Widget Item
class ListenerTableWidgetItem : public BaseTableWidgetItem<Listener> {
public:
    ListenerTableWidgetItem(Listener* listener, const QString& text)
        : BaseTableWidgetItem(listener, text) {}
};

// Base Table Widget Template
template <typename T_TableWidgetItem>
class BaseTableWidget : public QTableWidget {
protected:
    TeamserverWindow* mainWindow;  // Reference to the main window

public:
    BaseTableWidget(QWidget* parent = nullptr)
        : QTableWidget(parent), mainWindow(nullptr) {
        setSelectionMode(QAbstractItemView::SingleSelection);
    }

    void setMainWindow(TeamserverWindow* main_window) {
        mainWindow = main_window;
    }

    // Override selectedItems to return T_TableWidgetItem list
    QList<T_TableWidgetItem*> selectedItems() {
        QList<QTableWidgetItem*> items = QTableWidget::selectedItems();
        QList<T_TableWidgetItem*> typedItems;
        for (auto item : items) {
            typedItems.append(static_cast<T_TableWidgetItem*>(item));
        }
        return typedItems;
    }

    T_TableWidgetItem* selectedItem() {
        if (selectedItems().isEmpty()) {
            return nullptr;
        }
        return selectedItems().first();
    }

    virtual void repopulateItems() = 0;
};

// Listener Table Widget
class ListenerTableWidget : public BaseTableWidget<ListenerTableWidgetItem> {
public:
    ListenerTableWidget(QWidget* parent)
        : BaseTableWidget(parent) {
        setHorizontalHeaderLabels({"Name", "Address", "Port"});
    }

    void repopulateItems() override {
        if (mainWindow == nullptr) return;
        setRowCount(0);
        // Access LISTENERS from the main window
        for (Listener& listener : mainWindow->g_Listeners) {
            int row = rowCount();  // Get the current number of rows
            insertRow(row);  // Insert a new row at the end

            // Populate the row with listener data
            QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(listener.name));
            QTableWidgetItem* addressItem = new QTableWidgetItem(QString::fromStdString(listener.bind_address));
            QTableWidgetItem* portItem = new QTableWidgetItem(QString::number(listener.bind_port));

            // Align center
            nameItem->setTextAlignment(Qt::AlignCenter);
            addressItem->setTextAlignment(Qt::AlignCenter);
            portItem->setTextAlignment(Qt::AlignCenter);

            // Set the items in the corresponding columns
            setItem(row, 0, nameItem);
            setItem(row, 1, addressItem);
            setItem(row, 2, portItem);
        }
    }
};

// Agent Table Widget
class AgentTableWidget : public BaseTableWidget<AgentTableWidgetItem> {
public:
    AgentTableWidget(QWidget* parent)
        : BaseTableWidget(parent) {
        setHorizontalHeaderLabels({"ID", "Hostname", "User", "Process", "IP"});
    }

    void repopulateItems() override {
        if (mainWindow == nullptr) return;
        setRowCount(0);
        // Access AGENTS from the main window
        for (Agent& agent : mainWindow->g_Agents) {
            int row = rowCount();  // Append at the end
            insertRow(row);

            QTableWidgetItem* idItem       = new AgentTableWidgetItem(&agent, QString::fromStdString(agent.id));
            QTableWidgetItem* hostItem     = new AgentTableWidgetItem(&agent, QString::fromStdString(agent.hostname));
            QTableWidgetItem* userItem     = new AgentTableWidgetItem(&agent, QString::fromStdString(agent.user));
            QTableWidgetItem* processItem  = new AgentTableWidgetItem(&agent, QString::fromStdString(agent.process));
            QTableWidgetItem* ipItem       = new AgentTableWidgetItem(&agent, QString::fromStdString(agent.ip));
            QTableWidgetItem* lastSeenItem       = new AgentTableWidgetItem(&agent, QString::number(agent.last_alive));

            // Align center
            idItem->setTextAlignment(Qt::AlignCenter);
            hostItem->setTextAlignment(Qt::AlignCenter);
            userItem->setTextAlignment(Qt::AlignCenter);
            processItem->setTextAlignment(Qt::AlignCenter);
            ipItem->setTextAlignment(Qt::AlignCenter);
            lastSeenItem->setTextAlignment(Qt::AlignCenter);

            setItem(row, 0, idItem);
            setItem(row, 1, hostItem);
            setItem(row, 2, userItem);
            setItem(row, 3, processItem);
            setItem(row, 4, ipItem);
            setItem(row, 5, lastSeenItem);
        }
    }
};
