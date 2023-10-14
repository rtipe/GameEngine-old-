//
// Created by youba on 07/10/2023.
//

#include "Animation.hpp"
#include "ButtonNavigation.hpp"
#include "DisplayHP.hpp"
#include "Explosion.hpp"
#include "InputField.hpp"
#include "MissileHandler.hpp"
#include "MouseMovement.hpp"
#include "NetworkBase.hpp"
#include "Parallax.hpp"
#include "Timer.hpp"
#include "Uniti.hpp"
#include <iostream>

int main() {
  Uniti::Game::Core::initProject("../../json/project.json");

  Uniti::Game::Core::getScriptFactory().addScript<MouseMovement>(
      "MouseMovement");
  Uniti::Game::Core::getScriptFactory().addScript<ButtonNavigation>(
      "ButtonNavigation");
  Uniti::Game::Core::getScriptFactory().addScript<Animation>("Animation");
  Uniti::Game::Core::getScriptFactory().addScript<NetworkBase>("NetworkBase");
  Uniti::Game::Core::getScriptFactory().addScript<MissileHandler>(
      "MissileHandler");
  Uniti::Game::Core::getScriptFactory().addScript<DisplayHP>("DisplayHP");
  Uniti::Game::Core::getScriptFactory().addScript<Timer>("Timer");
  Uniti::Game::Core::getScriptFactory().addScript<Explosion>("Explosion");
  Uniti::Game::Core::getScriptFactory().addScript<InputField>("InputField");
  Uniti::Game::Core::getScriptFactory().addScript<Parallax>("Parallax");

  std::cout << Uniti::Game::Core::getProjectInfo().name << std::endl;
  Uniti::Game::Core::start();
}