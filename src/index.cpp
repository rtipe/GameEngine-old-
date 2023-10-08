//
// Created by youba on 07/10/2023.
//

#include <iostream>
#include "Uniti.hpp"
#include "MouseMovement.hpp"
#include "NetworkTest.hpp"

int main() {
    Uniti::Game::Core::initProject("../json/project.json");

    Uniti::Game::Core::getScriptFactory().addScript<MouseMovement>("MouseMovement");
    Uniti::Game::Core::getScriptFactory().addScript<NetworkTest>("NetworkTest");

    std::cout << Uniti::Game::Core::getProjectInfo().name << std::endl;
    Uniti::Game::Core::start();
}