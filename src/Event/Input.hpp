/*
** EPITECH PROJECT, 2023
** GameEngine
** File description:
** Input
*/


#pragma once
#include "UnitiGame.hpp"
#include <SFML/Graphics.hpp>

namespace UnitiGameEngine {
    class Input {
        public:
            Input(Uniti &game);
            void checkEvents();
            std::vector<std::string> &getEvents();
        private:
            std::vector<std::string> _events;
            Uniti &_game;
    };
}