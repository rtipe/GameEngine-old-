#define IndentWidth 4
//
// Created by youba on 05/10/2023.
//

#include "SceneManager.hpp"

#include <json/json.h>

#include <fstream>

#include "Uniti.hpp"

namespace Uniti::Game {
const Scene &SceneManager::getCurrentScene() const {
  return *this->_currentScene;
}

Scene &SceneManager::getCurrentScene() { return *this->_currentScene; }

const Scene &SceneManager::getGlobalScene() const {
  return *this->_globalScene;
}

Scene &SceneManager::getGlobalScene() { return *this->_globalScene; }

const std::vector<ScenePath> &SceneManager::getAllScenes() const {
  return Uniti::Game::Core::getProjectInfo().scenes;
}

const ScenePath &SceneManager::getScenePath(const std::string &name) const {
  auto it =
      std::find_if(this->getAllScenes().begin(), this->getAllScenes().end(),
                   [&](const ScenePath &path) { return path.name == name; });
  return *it;
}

void SceneManager::addScenePath(ScenePath &scenePath) {
  Uniti::Game::Core::getProjectInfo().scenes.push_back(scenePath);
}

bool SceneManager::changeScene(const std::string &name) {
  auto it =
      std::find_if(this->getAllScenes().begin(), this->getAllScenes().end(),
                   [&](const ScenePath &path) { return path.name == name; });
  if (it == this->getAllScenes().end())
    return false;
  this->_nextScene = *it;
  return true;
}

void SceneManager::update() {
  if (this->_nextScene != std::nullopt) {
    this->_currentScene = std::make_unique<Scene>(
        this->getSceneValue(this->_nextScene.value()), this->_nextScene->name);
    this->_nextScene = std::nullopt;
  }
  this->_currentScene->update();
  this->_globalScene->update();
}

void SceneManager::init() {
  auto globalScenePath =
      this->getScenePath(Uniti::Game::Core::getProjectInfo().globalScene);
  auto startScenePath =
      this->getScenePath(Uniti::Game::Core::getProjectInfo().startScene);
  this->_globalScene = std::make_unique<Scene>(
      this->getSceneValue(globalScenePath), globalScenePath.name);
  this->_currentScene = std::make_unique<Scene>(
      this->getSceneValue(startScenePath), startScenePath.name);
}

Json::Value SceneManager::getSceneValue(const ScenePath &scenePath) const {
  std::ifstream file(scenePath.path);
  Json::Value scene;
  file >> scene;
  return scene;
}
} // namespace Uniti::Game