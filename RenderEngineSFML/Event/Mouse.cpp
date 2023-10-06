//
// Created by youba on 05/10/2023.
//

#include "Mouse.hpp"

namespace Uniti::Render {
    void Mouse::update(Window &window) {
        std::string name;

        switch (window.getEvent().type) {
            case sf::Event::MouseButtonPressed:
                Mouse::_events.push_back("MOUSE_" + std::to_string(window.getEvent().mouseButton.button) + "_PRESSED");
                break;
            case sf::Event::MouseButtonReleased:
                Mouse::_events.push_back("MOUSE_" + std::to_string(window.getEvent().mouseButton.button) + "_RELEASED");
                break;
            default:
                break;
        }
    }

    bool Mouse::isMousePressed(const std::string &key) {
        std::string name = key;
        for (auto &c: name)
            c = toupper(c);
        std::string eventName = "MOUSE_" + name + "_PRESSED";
        return std::find(Mouse::_events.begin(), Mouse::_events.end(), eventName) != Mouse::_events.end();
    }

    bool Mouse::isMousePressed(Mouse::KeyMouse keyMouse) {
        std::string eventName = "MOUSE_" + std::to_string(keyMouse) + "_PRESSED";
        return std::find(Mouse::_events.begin(), Mouse::_events.end(), eventName) != Mouse::_events.end();
    }

    bool Mouse::isMouseReleased(const std::string &key) {
        std::string name = key;
        for (auto &c: name)
            c = toupper(c);
        std::string eventName = "MOUSE_" + name + "_RELEASED";
        return std::find(Mouse::_events.begin(), Mouse::_events.end(), eventName) != Mouse::_events.end();
    }

    bool Mouse::isMouseReleased(Mouse::KeyMouse keyMouse) {
        std::string eventName = "MOUSE_" + std::to_string(keyMouse) + "_RELEASED";
        return std::find(Mouse::_events.begin(), Mouse::_events.end(), eventName) != Mouse::_events.end();
    }

    Vector2f Mouse::getPosition(Window &window) {
        sf::Vector2<int> position = sf::Mouse::getPosition(window.getRenderWindow());
        return {static_cast<float>(position.x), static_cast<float>(position.y)};
    }

    std::vector<std::string> &Mouse::getEvents() {
        return Mouse::_events;
    }

    void Mouse::clearEvents() {
        Mouse::_events.clear();
    }
}