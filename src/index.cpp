//
// Created by youba on 07/10/2023.
//

#include <iostream>
#include "Uniti.hpp"
#include "MouseMovement.hpp"
#include "Animation.hpp"
#include "NetworkBase.hpp"
#include "MissileHandler.hpp"

int main() {
    Uniti::Game::Core::initProject("../../json/project.json");

    Uniti::Game::Core::getScriptFactory().addScript<MouseMovement>("MouseMovement");
    Uniti::Game::Core::getScriptFactory().addScript<Animation>("Animation");
    Uniti::Game::Core::getScriptFactory().addScript<NetworkBase>("NetworkBase");
    Uniti::Game::Core::getScriptFactory().addScript<MissileHandler>("MissileHandler");

    std::cout << Uniti::Game::Core::getProjectInfo().name << std::endl;
    Uniti::Game::Core::start();
}