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
        static void update(Window &window);
        static bool isPressed(const std::string &key);
        static bool isPressed(Key key);
        static bool isReleased(const std::string &key);
        static bool isReleased(Key key);
        static std::vector<std::string> &getEvents();
        static void clearEvents();
    };
}
