//
// Created by youba on 05/10/2023.
//

#include "Input.hpp"


namespace Uniti::Render {
    std::vector<std::string> Input::_events = {};

    void Input::update(Window &window) {
        std::string name;

        switch (window.getEvent().type) {
            case sf::Event::KeyPressed:
                Input::_events.push_back("KEY_" + std::to_string(window.getEvent().key.code) + "_PRESSED");
                break;
            case sf::Event::KeyReleased:
                Input::_events.push_back("KEY_" + std::to_string(window.getEvent().key.code) + "_RELEASED");
                break;
            default:
                break;
        }
    }

    bool Input::isPressed(const std::string &key) {
        std::string name = key;
        for (auto &c: name)
            c = toupper(c);
        std::string eventName = "KEY_" + name + "_PRESSED";
        return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
    }

    bool Input::isPressed(Input::Key key) {
        std::string eventName = "MOUSE_" + std::to_string(key) + "_PRESSED";
        return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
    }

    bool Input::isReleased(const std::string &key) {
        std::string name = key;
        for (auto &c: name)
            c = toupper(c);
        std::string eventName = "KEY_" + name + "_RELEASED";
        return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
    }

    bool Input::isReleased(Input::Key key) {
        std::string eventName = "MOUSE_" + std::to_string(key) + "_RELEASED";
        return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
    }

    std::vector<std::string> &Input::getEvents() {
        return Input::_events;
    }

    void Input::clearEvents() {
        Input::_events.clear();
    }
}