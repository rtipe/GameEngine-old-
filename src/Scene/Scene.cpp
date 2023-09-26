//
// Created by youba on 25/09/2023.
//

#include "Scene.hpp"

namespace UnitiGameEngine {

    Scene::Scene(const Json::Value &objects, Uniti &game, const std::string &name):
    _game(game),
    _name(name),
    _assetManager(game) {

    }

    void Scene::addObject(std::unique_ptr<IObject> object) {
        this->_objects.push_back(std::move(object));
    }

    bool Scene::removeObject(std::size_t id) {
        if (id >= this->_objects.size())
            return false;
        this->_objects.erase(this->_objects.begin() + id);
        return true;
    }

    void Scene::update() {
        for (auto &object : this->_objects)
            object->update();
    }

    const Uniti &Scene::getGame() const {
        return this->_game;
    }

    Uniti &Scene::getGame() {
        return this->_game;
    }

    const AssetManager &Scene::getAssetManager() const {
        return this->_assetManager;
    }

    AssetManager &Scene::getAssetManager() {
        return this->_assetManager;
    }

    const std::vector<std::unique_ptr<IObject>> &Scene::getObjects() const {
        return this->_objects;
    }

    std::vector<std::unique_ptr<IObject>> &Scene::getObjects() {
        return this->_objects;
    }

    const IObject &Scene::get(const std::string &name) const {
        auto it = std::find_if(this->_objects.begin(), this->_objects.end(), [name](const std::unique_ptr<IObject> &object) {
            return object->getName() == name;
        });
        if (it == this->_objects.end())
            throw std::invalid_argument("object's name not found");
        return it->operator*();
    }

    IObject &Scene::get(const std::string &name) {
        auto it = std::find_if(this->_objects.begin(), this->_objects.end(), [name](const std::unique_ptr<IObject> &object) {
            return object->getName() == name;
        });
        if (it == this->_objects.end())
            throw std::invalid_argument("object's name not found");
        return it->operator*();
    }

    const std::string &Scene::getName() const {
        return this->_name;
    }
}
