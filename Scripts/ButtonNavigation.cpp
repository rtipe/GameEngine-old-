/*
** EPITECH PROJECT, 2023
** GameEngine
** File description:
** ButtonNavigation
*/

#include "ButtonNavigation.hpp"
#include "Uniti.hpp"
#include "Mouse.hpp"
#include "MouseMovement.hpp"
#include <iostream>

ButtonNavigation::ButtonNavigation(Uniti::Game::Object &gameObject) :
    Uniti::Game::AScript(gameObject)
{
}

void ButtonNavigation::start() { }

void ButtonNavigation::update() {

    Uniti::Render::Vector2f positionMouse = Uniti::Render::Mouse::getPosition(Uniti::Game::Core::getWindow());

    float buttonX = 150;
    float buttonY = 150;
    float buttonWidth = 600;
    float buttonHeight = 200;

    if (positionMouse.getX() >= buttonX &&
        positionMouse.getX() <= buttonX + buttonWidth &&
        positionMouse.getY() >= buttonY &&
        positionMouse.getY() <= buttonY + buttonHeight &&
        Uniti::Render::Mouse::isMousePressed(Uniti::Render::Mouse::KeyMouse::LEFT)) {
        std::cout << "Clic de souris sur le bouton détecté" << std::endl;
        Uniti::Game::Core::getSceneManager().changeScene(_redirections);
    }
}

void ButtonNavigation::awake(const Json::Value &value) {
    this->_currentButton = value.get("currentButton", "").asString();
    this->_redirections = value.get("redirection", "").asString();
    this->_data.width = value.get("width", 0.0).asFloat();
    this->_data.height = value.get("height", 0.0).asFloat();
    std::cout << this->_currentButton << std::endl;
    std::cout << this->_redirections << std::endl;
}
