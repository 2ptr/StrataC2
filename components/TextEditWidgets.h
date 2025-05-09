#pragma once
#ifndef TEXTEDITWIDGETS_H
#define TEXTEDITWIDGETS_H
#include <QTableWidgetItem>
#include <QTextEdit>

class TeamserverWindow;  // Forward declaration is enough for the header

class CommandsTextEdit : public QTextEdit {
    Q_OBJECT
    public:
    TeamserverWindow* mainWindow = nullptr;
    CommandsTextEdit(QWidget *parent = nullptr);
    void setMainWindow(TeamserverWindow* main_window);
    void repopulateItems();  // Declaration only
    static std::string format_command(std::string command);
};

#endif //TEXTEDITWIDGETS_H