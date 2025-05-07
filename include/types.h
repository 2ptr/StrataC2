//
// Created by jake.otte on 5/5/2025.
//

#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <vector>
#include <map>
#include <thread>
#include "httplib.h"
#include <QThread>

class HTTPListenerThread : public QThread {
    Q_OBJECT

public:
    httplib::Server svr;
    explicit HTTPListenerThread(const char* address, int port, QObject *parent = nullptr)
        : QThread(parent), bind_address(address), bind_port(port) {}

    bool is_valid_bind() {
        // Try to bind the server
        if (!svr.bind_to_port(bind_address, bind_port)) {
            printf("Failed to bind to port\n");
            return false;
        }
        return true;
    }

protected:
    void run() override {
        // Set up a POST callback for all routes
        svr.set_post_routing_handler([](const httplib::Request &req, httplib::Response &res) {
            printf("Received POST to: %s\n", req.path.c_str());
            res.status = 200;
            res.set_content("{\"status\":\"ok\"}", "application/json");
            return httplib::Server::HandlerResponse::Handled;
        });

        // Start the server
        printf("Starting HTTP server...\n");
        svr.listen_after_bind(); // Blocking
    }

private:
    const char* bind_address;
    int bind_port;
};

class Listener {
public:
    std::string name;
    std::string bind_address;
    int bind_port;
    HTTPListenerThread* listenerThread = nullptr;  // The QThread that runs HTTP servers

    bool tryHttpStartListener() {
        // Create a thread
        listenerThread = new HTTPListenerThread(this->bind_address.c_str(), this->bind_port);
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

    Listener(const std::string& name, const std::string& bind_address, const int bind_port)
        : name(name), bind_address(bind_address), bind_port(bind_port) {}
};

class Agent {
public:
    // Metadata
    std::string id;
    std::string hostname;
    std::string user;
    std::string process;
    std::string ip;

    // CFG/LOCALS
    int sleep;
    int last_alive;
    std::vector<std::string> cmd_history;
    std::vector<std::map<std::string,std::string>> cmd_queue;

    Agent(const std::string& id, const std::string& hostname, const std::string& user, const std::string& process, const std::string& ip)
        : id(id), hostname(hostname), user(user), process(process), ip(ip), sleep(0), last_alive(0) {
    }
};

#endif //TYPES_H
