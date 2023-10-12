//
// Created by youba on 07/10/2023.
//

#include <iostream>
#include "Uniti.hpp"
#include "MouseMovement.hpp"
#include "NetworkBase.hpp"

int main() {
    Uniti::Game::Core::initProject("../../json/project.json");

    Uniti::Game::Core::getScriptFactory().addScript<MouseMovement>("MouseMovement");
    Uniti::Game::Core::getScriptFactory().addScript<NetworkBase>("NetworkBase");

    std::cout << Uniti::Game::Core::getProjectInfo().name << std::endl;
    Uniti::Game::Core::start();
}