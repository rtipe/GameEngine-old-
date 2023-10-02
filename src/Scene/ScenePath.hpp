//
// Created by youba on 25/09/2023.
//

#pragma once

#include <utility>

namespace UnitiGameEngine {
    struct ScenePath {
        ScenePath(std::string _name, std::string _path): name(std::move(_name)), path(std::move(_path)) {}
        std::string name;
        std::string path;
    };
}

