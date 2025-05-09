//
// Created by jake.otte on 5/5/2025.
//

#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <vector>
#include <map>
#include "httplib.h"

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
