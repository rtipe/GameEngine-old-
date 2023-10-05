//
// Created by youba on 05/10/2023.
//

#pragma once


#include <string>
#include <vector>
#include "Window.hpp"

namespace Uniti::Render {
    class Input {
    public:
        enum Key {
            A,
        };
        void update(Window &window);
        bool isPressed(const std::string &key);
        bool isPressed(Key key);
        bool isReleased(const std::string &key);
        bool isReleased(Key key);
        std::vector<std::string> &getEvents();
        void clearEvents();
    };
} // Uniti
// Render
