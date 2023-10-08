//
// Created by youba on 05/10/2023.
//

#include "Scene.hpp"

namespace Uniti::Game {
    Scene::Scene(const Json::Value &scene, const std::string &name):
    _assetManager(scene["assets"]),
    _objectManager(scene["objects"], *this),
    _name(name) { }

    void Scene::update() {
        this->_objectManager.update();
    }

    const ObjectManager &Scene::getObjects() const {
        return this->_objectManager;
    }

    ObjectManager &Scene::getObjects() {
        return this->_objectManager;
    }

    const AssetManager &Scene::getAssetManager() const {
        return this->_assetManager;
    }

    AssetManager &Scene::getAssetManager() {
        return this->_assetManager;
    }

    const std::string &Scene::getName() const {
        return this->_name;
    }
}