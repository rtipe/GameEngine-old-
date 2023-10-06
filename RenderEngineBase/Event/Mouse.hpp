//
// Created by youba on 05/10/2023.
//

#pragma once


#include <string>
#include <vector>
#include "Window.hpp"
#include "Vector2f.hpp"

namespace Uniti::Render {
    class Mouse {
    public:
        enum KeyMouse {
            LEFT,
            RIGHT,
            MIDDLE
        };
        void update(Window &window);
        bool isMousePressed(const std::string &key);
        bool isMousePressed(KeyMouse keyMouse);
        bool isMouseReleased(const std::string &key);
        bool isMouseReleased(KeyMouse keyMouse);
        Vector2f getPosition();
        std::vector<std::string> &getEvents();
        void clearEvents();
    };
}
