//
// Created by youba on 07/10/2023.
//

#include <iostream>
#include "Uniti.hpp"

int main() {
    Uniti::Game::Core::initProject("../json/project.json");

    std::cout << Uniti::Game::Core::getProjectInfo().name << std::endl;
    Uniti::Game::Core::start();
}