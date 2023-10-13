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
        static void update(Window &window);
        static bool isMousePressed(const std::string &key);
        static bool isMousePressed(KeyMouse keyMouse);
        static bool isMouseReleased(const std::string &key);
        static bool isMouseReleased(KeyMouse keyMouse);
        static Vector2f getPosition(Window &window);
        static std::vector<std::string> &getEvents();
        static void clearEvents();
    private:
        static std::vector<std::string> _events;
    };
}
