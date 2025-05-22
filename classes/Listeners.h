#pragma once

#include <string>
#include "Callbacks.h"
#include <QThread>
#include "../lib/httplib.h"
#include "../lib/json.hpp"
#ifndef LISTENERS_H
#define LISTENERS_H
class TeamserverWindow;  // Forward declaration

///
/// HTTPListenerThread CONTAINS ALL REQUEST HANDLING
///
class HTTPListenerThread : public QThread {
    Q_OBJECT

public:
    httplib::Server svr;
    TeamserverWindow *main_window = nullptr;

    bool is_valid_bind() {
        // Try to bind the server
        if (!svr.bind_to_port(bind_address, bind_port)) {
            printf("Failed to bind to port\n");
            return false;
        }
        return true;
    }
    void setMainWindow(TeamserverWindow* mw) {
        main_window = mw;
    }

    explicit HTTPListenerThread(const char* address, int port, QObject *parent = nullptr)
        : QThread(parent), bind_address(address), bind_port(port) {}

protected:
    // REQUEST HANDLING
    void run() override;

private:
    const char* bind_address;
    int bind_port;
};

enum ListenerTypes {
    HTTP,
    HTTPS,
    AZURE
};

///
/// LISTENER CLASS
///
class Listener {
public:
    std::string name;
    ListenerTypes type;
    std::string bind_address;
    int bind_port;
    std::map<std::wstring, int> callbacks;

    TeamserverWindow *main_window = nullptr;
    HTTPListenerThread* listenerThread = nullptr;  // The QThread that runs HTTP servers

    bool tryHttpStartListener() {
        // Create a thread
        listenerThread = new HTTPListenerThread(this->bind_address.c_str(), this->bind_port);
        listenerThread->setMainWindow(main_window);
        if (!listenerThread->is_valid_bind()) {
            return false;
        }
        // Start the thread running
        listenerThread->start();
        return true;
    }
    void stopListener() {
        if (listenerThread) {
            listenerThread->quit();  // Request thread to exit
            listenerThread->wait();  // Wait until the thread finishes
            delete listenerThread;   // Clean up
            listenerThread = nullptr;
        }
    }

    void setMainWindow(TeamserverWindow* mw) {
        main_window = mw;
    }

    Listener(const std::string& name, const ListenerTypes type, const std::string& bind_address, const int bind_port, const std::map<std::wstring, int>& callbacks)
        : name(name), type(), bind_address(bind_address), bind_port(bind_port), callbacks(callbacks) {
    }
};


#endif //LISTENERS_H
