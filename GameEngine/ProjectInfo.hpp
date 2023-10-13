//
// Created by youba on 05/10/2023.
//

#pragma once

#include <string>
#include <vector>
#include <json/json.h>
#include "ScenePath.hpp"

namespace Uniti::Game {
    struct ProjectInfo {
        ProjectInfo(const std::string &projectPath);
        std::string name;
        std::string startScene;
        std::string globalScene;
        std::string directoryScenePath;
        std::vector<ScenePath> scenes;
        int width;
        int height;
        std::string title;
        int framerateLimit;
        std::string iconPath;
        Json::Value data;
        int port;
        int latence;
    };
}

