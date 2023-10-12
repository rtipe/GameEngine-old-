/*
** EPITECH PROJECT, 2023
** GameEngine
** File description:
** ButtonNavigation
*/

#pragma once

#include "AScript.hpp"

struct ButtonNavigationData {
    float width;
    float height;
};

class ButtonNavigation: public Uniti::Game::AScript {
    public:
        explicit ButtonNavigation(Uniti::Game::Object &gameObject);
        void start() override;
        void update() override;
        void awake(const Json::Value &value) override;
    private:
        ButtonNavigationData _data;
        std::string _currentButton;
        std::string _redirections;
};
