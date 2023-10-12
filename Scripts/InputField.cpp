//
// Created by azerlus on 12/10/2023.
//

#include <iostream>
#include "Uniti.hpp"
#include "Mouse.hpp"
#include "Input.hpp"
#include "InputField.hpp"
#include "Text.hpp"
#include <iostream>

InputField::InputField(Uniti::Game::Object &gameObject) : AScript(gameObject) { }

void InputField::start() {

}

void InputField::update() {
    this->checkActive();
    this->writeInputField();
}

void InputField::awake(const Json::Value &value) {
    this->_active = value.get("active", false).asBool();
    this->_height = value.get("height", 100).asFloat();
    this->_width = value.get("width", 300).asFloat();
    this->_maxChar = value.get("maxChar", 32).asInt();
    this->_minChar = value.get("minChar", 5).asInt();
}

void InputField::checkActive() {
    if (Uniti::Render::Mouse::isMousePressed(Uniti::Render::Mouse::KeyMouse::LEFT)) {
        Uniti::Render::Vector2f positionMouse = Uniti::Render::Mouse::getPosition(Uniti::Game::Core::getWindow());
        float xPos = this->getGameObject().getTransform().getPosition().getX();
        float yPos = this->getGameObject().getTransform().getPosition().getY();

        if ((positionMouse.getX() >= xPos && positionMouse.getX() <= xPos + this->_width) &&
            (positionMouse.getY() >= yPos && positionMouse.getY() <= yPos + this->_height)) {
            this->_active = true;
            std::cout << "activated" << std::endl;
        } else {
            this->_active = false;
            std::cout << "deactivated" << std::endl;
        }
    }
}

void InputField::writeInputField() {
    std::vector<std::string> &events = Uniti::Render::Input::getEvents();
    std::string text;
    int nbReturn;

    for (int i = 0; i < events.size(); i++) {
        if (events[i].substr(events[i].length() - 8) == "_PRESSED") {
            size_t firstUnderscore = events[i].find('_');
            size_t secondUnderscore = events[i].find('_', firstUnderscore + 1);
            int keyId = stoi(events[i].substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1));
            std::cout << events[i] << std::endl;
            if (keyId >= 0 && keyId <= 25)
                text += keyId + 65;
            if (keyId == 57)
                text += "  ";
            if (keyId == 59)
                nbReturn++;
        }
    }
    auto &currentText = dynamic_cast<Uniti::Render::Text &>(this->getGameObject().getPrintable());
    std::string nextString = currentText.getString() + text;
    for (int i = 0; i < nbReturn && nextString.size() >= 1; i++)
        nextString = nextString.substr(0, nextString.length() - nbReturn);
    currentText.setString(nextString);
}