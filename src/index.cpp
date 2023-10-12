//
// Created by youba on 07/10/2023.
//

#include <iostream>
#include "Uniti.hpp"
#include "MouseMovement.hpp"
#include "NetworkTest.hpp"
#include "Animation.hpp"

int main() {
    Uniti::Game::Core::initProject("../../json/project.json");

    Uniti::Game::Core::getScriptFactory().addScript<MouseMovement>("MouseMovement");
    Uniti::Game::Core::getScriptFactory().addScript<NetworkTest>("NetworkTest");
    Uniti::Game::Core::getScriptFactory().addScript<Animation>("Animation");

    std::cout << Uniti::Game::Core::getProjectInfo().name << std::endl;
    Uniti::Game::Core::start();
}