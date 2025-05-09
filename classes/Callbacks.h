//
// Created by jake.otte on 5/9/2025.
//

#ifndef CALLBACKS_H
#define CALLBACKS_H
#include <string>
#include <vector>
#include "../lib/json.hpp"

class CallbackMetadata {
public:
    std::string id;
    std::string hostname;
    std::string user;
    std::string process;
    std::string ip;
    int sleep = 0;

    // Function to parse JSON into the class
    static CallbackMetadata from_json(const nlohmann::json& j) {
        CallbackMetadata metadata;
        if (j.contains("id")) metadata.id = j["id"].get<std::string>();
        if (j.contains("hostname")) metadata.hostname = j["hostname"].get<std::string>();
        if (j.contains("user")) metadata.user = j["user"].get<std::string>();
        if (j.contains("process")) metadata.process = j["process"].get<std::string>();
        if (j.contains("ip")) metadata.ip = j["ip"].get<std::string>();
        if (j.contains("sleep")) metadata.sleep = j["sleep"].get<int>();
        return metadata;
    }
};

class CallbackFull {
public:
    CallbackMetadata metadata;
    std::vector<std::string> data;

    // Function to parse JSON into the class
    static CallbackFull from_json(const nlohmann::json& j) {
        CallbackFull full;
        if (j.contains("metadata")) full.metadata = CallbackMetadata::from_json(j["metadata"]);
        if (j.contains("data")) full.data = j["data"].get<std::vector<std::string>>();
        return full;
    }
};

#endif //CALLBACKS_H
