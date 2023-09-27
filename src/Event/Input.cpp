/*
** EPITECH PROJECT, 2023
** GameEngine
** File description:
** Input
*/

#include "Input.hpp"

static const std::string keysName[] = {
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Esc",
    "ctrl",
    "Shift",
    "Alt",
    "LSystem",
    "ctrl",
    "Shift",
    "Alt",
    "RSystem",
    "Menu",
    "LBracket",
    "RBracket",
    "Semicolon",
    "Comma",
    "Period",
    "Quote",
    "Slash",
    "Backslash",
    "Tilde",
    "Equal",
    "Hyphen",
    "Space",
    "Enter",
    "Backspace",
    "Tab",
    "PageUp",
    "PageDown",
    "End",
    "Home",
    "Insert",
    "Delete",
    "Add",
    "Subtract",
    "Multiply",
    "Divide",
    "Left",
    "Right",
    "Up",
    "Down",
    "Numpad0",
    "Numpad1",
    "Numpad2",
    "Numpad3",
    "Numpad4",
    "Numpad5",
    "Numpad6",
    "Numpad7",
    "Numpad8",
    "Numpad9",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
    "F13",
    "F14",
    "F15",
    "Pause",
};

namespace UnitiGameEngine
{
    Input::Input(Uniti &game) : _game(game) {}

    std::vector<std::string> &Input::getEvents()
    {
    }

    void Input::checkEvents()
    {
        sf::Event event;
        std::string name;

        this->_events.clear();
        while (this->_game.getWindow().pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                this->_events.push_back("QUIT");
                break;
            case sf::Event::KeyPressed:
                name = keysName[event.key.code];
                for (auto &c : name)
                    c = toupper(c);
                this->_events.push_back("KEY_" + name + "_PRESSED");
                break;
            case sf::Event::MouseButtonPressed:
                this->_events.push_back("MOUSE_" + std::to_string(event.mouseButton.button + 1) + "_PRESSED");
                break;
            case sf::Event::Resized:
                this->_events.push_back("WINDOW_RESIZE");
                break;
            case sf::Event::LostFocus:
                this->_events.push_back("WINDOW_MINIMIZE");
                break;
            default:
                break;
            }
        }
    }
}