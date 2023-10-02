/*
** EPITECH PROJECT, 2023
** GameEngine
** File description:
** Input
*/


#pragma once
#include <SFML/Graphics.hpp>

namespace UnitiGameEngine {
    class Input {
        public:
            Input();
            void checkEvents(sf::Event &event);
            bool isPressed(std::string key);
            bool isReleased(std::string key);
            bool isMousePressed(std::string key);
            bool isMouseReleased(std::string key);
            std::vector<std::string> &getEvents();
            void clearEvents();
        private:
            std::vector<std::string> _events;
    };
}