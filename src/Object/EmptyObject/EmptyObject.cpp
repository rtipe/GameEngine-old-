//
// Created by youba on 26/09/2023.
//

#include "EmptyObject.hpp"

namespace UnitiGameEngine {

    EmptyObject::EmptyObject(Scene &scene, Uniti &game, const Json::Value &values): _scene(scene), _game(game) {
        const Json::Value position = values["position"];
        const Json::Value scale = values["scale"];
        const Json::Value scripts = values["scripts"];
        const Json::Value children = values["children"];
        Transform transform;

        transform.position.x = position.get("x", 0).asFloat();
        transform.position.y = position.get("y", 0).asFloat();
        transform.position.z = position.get("z", 0).asFloat();
        transform.rotation = values.get("rotation", 0).asFloat();
        transform.scale.x = scale.get("x", 0).asFloat();
        transform.scale.y = scale.get("y", 0).asFloat();

        for (int i = 0; i < children.size(); i++) {
            const std::string type = children[i]["type"].asString();

            if (type == "empty") {
                this->_children.push_back(std::make_unique<EmptyObject>(this->_game, children[i]));
            } else if (type == "sprite") {
                this->_children.push_back(std::make_unique<SpriteObject>(this->_game, children[i]));
            } else if (type == "text") {
                this->_children.push_back(std::make_unique<TextObject>(this->_game, children[i]));
            } else {
                //TODO error
            }
        }
        for (int i = 0; i < scripts.size(); i++) {
            this->_scriptManager.addScript(this->_game.getScriptFactory().createScript(scripts[i]["name"].asString(), this->_game, *this), scripts[i]["name"].asString());
        }
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
