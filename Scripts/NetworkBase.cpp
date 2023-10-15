//
// Created by youba on 08/10/2023.
//

#include "NetworkBase.hpp"
#include <iostream>
#include "InputField.hpp"
#include "Objects.hpp"
#include "Uniti.hpp"

NetworkBase::NetworkBase(Uniti::Game::Object &gameObject) : AScript(gameObject)
{
}

void NetworkBase::start()
{
    Uniti::Game::Core::getNetwork().addServer("game", "127.0.0.1", 7070, InputField::_username);
}

void NetworkBase::update()
{
}

void NetworkBase::awake(const Json::Value &value)
{
}
