//
// Created by jake.otte on 5/12/2025.
//

#ifndef COMMANDHELPER_H
#define COMMANDHELPER_H
class TeamserverWindow;


class CommandHelper {
public:
    TeamserverWindow* mainWindow;  // Reference to the main window
    void handle_command();
    void setMainWindow(TeamserverWindow* main_window) {
        mainWindow = main_window;
    }

    CommandHelper() = default;
    ~CommandHelper() = default;
};



#endif //COMMANDHELPER_H
