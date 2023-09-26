//
// Created by youba on 26/09/2023.
//

#include "EmptyObject.hpp"

namespace UnitiGameEngine {

    EmptyObject::EmptyObject(Uniti &game, const Json::Value &values): _game(game) {

        this->_scriptManager.start();
    }

    void EmptyObject::update() {
        if (!this->_isEnabled) return;
        this->_scriptManager.update();
        for (const auto &child : this->_children)
            child->update();
    }

    const std::string &EmptyObject::getName() const {
        return this->_name;
    }

    void EmptyObject::setEnable(bool value) {
        this->_isEnabled = value;
    }

    bool EmptyObject::isDisabled() const {
        return !this->_isEnabled;
    }

    const Transform &EmptyObject::getTransform() const {
        return this->_transform;
    }

    Transform &EmptyObject::getTransform() {
        return this->_transform;
    }

    ObjectTypes EmptyObject::getType() const {
        return ObjectTypes::Empty;
    }

    const std::vector<std::unique_ptr<IObject>> &EmptyObject::getChildren() const {
        return this->_children;
    }

    std::vector<std::unique_ptr<IObject>> &EmptyObject::getChildren() {
        return this->_children;
    }

    const Uniti &EmptyObject::getGame() const {
        return this->_game;
    }

    Uniti &EmptyObject::getGame() {
        return this->_game;
    }

    ScriptManager &EmptyObject::getScriptManager() {
        return this->_scriptManager;
    }

    void EmptyObject::display() {}
}
