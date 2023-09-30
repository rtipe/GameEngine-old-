//
// Created by youba on 25/09/2023.
//

#include <iostream>
#include "Scene.hpp"
#include "../Object/SpriteObject/SpriteObject.hpp"
#include "../Object/TextObject/TextObject.hpp"
#include "../Object/EmptyObject/EmptyObject.hpp"
#include "../Object/IObject.hpp"

namespace UnitiGameEngine {

    Scene::Scene(const Json::Value &objects, const std::string &name):
    _name(name),
    _assetManager() {
        Json::Value elements = objects["objects"];

        this->_assetManager.loadAssets(objects["assets"]);
        for (int i = 0; i < elements.size(); i++) {
            const std::string type = elements[i]["type"].asString();

            if (type == "empty") {
                this->_objects.push_back(std::make_unique<EmptyObject>(*this, elements[i]));
            } else if (type == "sprite") {
                this->_objects.push_back(std::make_unique<SpriteObject>(*this, elements[i]));
            } else if (type == "text") {
                this->_objects.push_back(std::make_unique<TextObject>(*this, elements[i]));
            } else {
                //TODO error
            }
        }
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
