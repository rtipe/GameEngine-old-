//
// Created by youba on 25/09/2023.
//

#include <fstream>
#include "SceneManager.hpp"

namespace UnitiGameEngine {

    SceneManager::SceneManager(Uniti &game): _game(game) {

    }

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
        return this->_game.getProjectInfo().scenes;
    }

    void SceneManager::addScenePath(ScenePath &scenePath) {
        return this->_game.getProjectInfo().scenes.push_back(scenePath);
    }

    bool SceneManager::removeScenePath(const std::string &name) {
        std::vector<ScenePath>::iterator it;
        it = remove_if(this->_game.getProjectInfo().scenes.begin(), this->_game.getProjectInfo().scenes.end(),
        [name](ScenePath &path) {
            return path.name == name;
        });
        return it != this->_game.getProjectInfo().scenes.end();
    }

    bool SceneManager::changeScene(const std::string &name) {
        auto it = std::find_if(this->_game.getProjectInfo().scenes.begin(), this->_game.getProjectInfo().scenes.end(),
        [name](ScenePath &path) {
            return path.name == name;
        });
        if (it == this->_game.getProjectInfo().scenes.end())
            return false;
        this->_nextScene = *it;
        return true;
    }

    void SceneManager::update() {
        if (this->_nextScene != std::nullopt) {
            std::ifstream file(this->_nextScene->path);
            Json::Value scene;
            file >> scene;
            this->_currentScene = std::make_unique<Scene>(scene, this->_game, this->_nextScene->name);
        }
        this->_currentScene->update();
        this->_globalScene->update();
        this->_displayer.display();
    }
}
