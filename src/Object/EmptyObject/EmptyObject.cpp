//
// Created by youba on 26/09/2023.
//

#include "EmptyObject.hpp"
#include "../SpriteObject/SpriteObject.hpp"
#include "../TextObject/TextObject.hpp"
#include "../../UnitiGame.hpp"

namespace UnitiGameEngine {

    EmptyObject::EmptyObject(Scene &scene, const Json::Value &values): _scene(scene) {
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
                this->_children.push_back(std::make_unique<EmptyObject>(scene, children[i]));
            } else if (type == "sprite") {
                this->_children.push_back(std::make_unique<SpriteObject>(scene, children[i]));
            } else if (type == "text") {
                this->_children.push_back(std::make_unique<TextObject>(scene, children[i]));
            } else {
                //TODO error
            }
        }
        for (int i = 0; i < scripts.size(); i++) {
            auto name = scripts[i]["name"].asString();
            this->_scriptManager.addScript(Uniti::getInstance().getScriptFactory().createScript(name, *this), name);
            this->_scriptManager.getScript(name).awake(scripts[i]);
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

    const Scene &EmptyObject::getScene() const {
        return this->_scene;
    }

    Scene &EmptyObject::getScene() {
        return this->_scene;
    }

    ScriptManager &EmptyObject::getScriptManager() {
        return this->_scriptManager;
    }

    void EmptyObject::display() {}
}
