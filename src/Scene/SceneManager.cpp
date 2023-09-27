//
// Created by youba on 25/09/2023.
//

#include <fstream>
#include "SceneManager.hpp"
#include "../UnitiGame.hpp"

namespace UnitiGameEngine {

    SceneManager::SceneManager() {}

    const Scene &SceneManager::getCurrentScene() const {
        return this->_currentScene.operator*();
    }

    Scene &SceneManager::getCurrentScene() {
        return this->_currentScene.operator*();
    }

    const Scene &SceneManager::getGlobalScene() const {
        return this->_globalScene.operator*();
    }

    Scene &SceneManager::getGlobalScene() {
        return this->_globalScene.operator*();
    }

    const std::vector<ScenePath> &SceneManager::getAllScenes() const {
        return Uniti::getInstance().getProjectInfo().scenes;
    }

    void SceneManager::addScenePath(ScenePath &scenePath) {
        return Uniti::getInstance().getProjectInfo().scenes.push_back(scenePath);
    }

    bool SceneManager::removeScenePath(const std::string &name) {
        std::vector<ScenePath>::iterator it;
        it = remove_if(Uniti::getInstance().getProjectInfo().scenes.begin(), Uniti::getInstance().getProjectInfo().scenes.end(),
        [name](ScenePath &path) {
            return path.name == name;
        });
        return it != Uniti::getInstance().getProjectInfo().scenes.end();
    }

    bool SceneManager::changeScene(const std::string &name) {
        auto it = std::find_if(Uniti::getInstance().getProjectInfo().scenes.begin(), Uniti::getInstance().getProjectInfo().scenes.end(),
        [name](ScenePath &path) {
            return path.name == name;
        });
        if (it == Uniti::getInstance().getProjectInfo().scenes.end())
            return false;
        this->_nextScene = *it;
        return true;
    }

    void SceneManager::update() {
        if (this->_nextScene != std::nullopt) {
            std::ifstream file(this->_nextScene->path);
            Json::Value scene;
            file >> scene;
            this->_currentScene = std::make_unique<Scene>(scene, this->_nextScene->name);
        }
        this->_currentScene->update();
        this->_globalScene->update();
        this->_displayer.display();
    }

    const Displayer &SceneManager::getDisplayer() const {
        return this->_displayer;
    }

    Displayer &SceneManager::getDisplayer() {
        return this->_displayer;
    }
}
