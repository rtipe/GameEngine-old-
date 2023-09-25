//
// Created by youba on 25/09/2023.
//

#pragma once

#include <json/json.h>
#include "Scene/ScenePath.hpp"

namespace UnitiGameEngine {
    struct ProjectInfo {
        public:
            ProjectInfo(const Json::Value &project);
            std::string name;
            std::string startScene;
            std::string globalScene;
            std::string directoryScenePath;
            std::vector<ScenePath> scenes;
        private:
    };
}