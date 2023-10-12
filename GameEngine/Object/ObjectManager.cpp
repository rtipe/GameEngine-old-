//
// Created by youba on 05/10/2023.
//

#include "Scene.hpp"
#include "Object.hpp"

namespace Uniti::Game {
    ObjectManager::ObjectManager(const Json::Value &value, Scene &scene) {
        for (const auto &object : value)
            this->_objects.push_back(std::make_unique<Object>(object, scene));
    }

    ObjectManager::ObjectManager(const std::vector<std::unique_ptr<Object>> &objects) {
        for (const auto &object : objects)
            this->_objects.push_back(std::make_unique<Object>(*object));
    }

    void ObjectManager::add(std::unique_ptr<Object> object) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_inObjects.push_back(std::move(object));
    }

    void ObjectManager::remove(const std::string &name) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_outObjects.push_back(name);
    }

    const std::vector<std::unique_ptr<Object>> &ObjectManager::getObjects() const {
        return this->_objects;
    }

    std::vector<std::unique_ptr<Object>> &ObjectManager::getObjects() {
        return this->_objects;
    }

    void ObjectManager::update() {
        while (!this->_outObjects.empty()) {
            std::erase_if(this->_objects, [&] (const std::unique_ptr<Object> &object) {
                return object->getName() == this->_outObjects.front();
            });
            this->_outObjects.erase(this->_outObjects.begin());
        }
        for (const auto &object: this->_objects)
            object->update();
        while (!this->_inObjects.empty()) {
            this->_objects.push_back(std::move(this->_inObjects[0]));
            this->_inObjects.erase(this->_inObjects.begin());
        }
    }

    void ObjectManager::emitEvent(const std::string &name, const Json::Value &value) {
        for (const auto &object : this->_objects)
            object->getScriptManager().emitEvent(name, value);
    }
}