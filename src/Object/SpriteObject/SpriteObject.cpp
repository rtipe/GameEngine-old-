//
// Created by youba on 26/09/2023.
//

#include "SpriteObject.hpp"

namespace UnitiGameEngine {

    SpriteObject::SpriteObject(Scene &scene, Uniti &game, const Json::Value &values): _scene(scene), _game(game) {
        const Json::Value scripts = values["scripts"];

        if (values.isMember("name"))
            this->_name = values["name"].asString();
        if (values.isMember("position")) {
            this->_transform.position.x = values["position"]["x"].asFloat();
            this->_transform.position.y = values["position"]["y"].asFloat();
        }
        if (values.isMember("rotation")) {
            this->_transform.rotation.angle = values["rotation"].asFloat();
        }
        if (values.isMember("scale")) {
            this->_transform.scale.x = values["scale"]["x"].asFloat();
            this->_transform.scale.y = values["scale"]["y"].asFloat();
        }
        if (values.isMember("textureName")) {
    //to do: add texture manager
        }
        for (const auto &child : values["children"]) {
            if (child["type"].asString() == "sprite") {
                this->_children.push_back(std::make_unique<SpriteObject>(this->_game, child));
            } else if (child["type"].asString() == "text") {
                this->_children.push_back(std::make_unique<TextObject>(this->_game, child));
            } else if (child["type"].asString() == "empty") {
                this->_children.push_back(std::make_unique<EmptyObject>(this->_game, child));
            } else {
                throw std::runtime_error("Unknown object type");
            }
        }
        for (int i = 0; i < scripts.size(); i++) {
            this->_scriptManager.addScript(this->_game.getScriptFactory().createScript(scripts[i]["name"].asString(), this->_game, *this), scripts[i]["name"].asString());
        }
        this->_scriptManager.start();
    }

    void SpriteObject::update() {
        if (!this->_isEnabled) return;
        this->_scriptManager.update();
        this->_game.getSceneManager().getDisplayer().add(*this);
        for (const auto &child : this->_children)
            child->update();
    }

    void SpriteObject::display() {
        this->_sprite.setPosition(this->_transform.position.x, this->_transform.position.y);
        this->_sprite.setRotation(this->_transform.rotation.angle);
        this->_sprite.setScale(this->_transform.scale.x, this->_transform.scale.y);
        this->_game.getWindow().draw(this->_sprite);
    }

    const std::string &SpriteObject::getName() const {
        return this->_name;
    }

    void SpriteObject::setEnable(bool value) {
        this->_isEnabled = value;
    }

    bool SpriteObject::isDisabled() const {
        return !this->_isEnabled;
    }

    const Transform &SpriteObject::getTransform() const {
        return this->_transform;
    }

    Transform &SpriteObject::getTransform() {
        return this->_transform;
    }

    ObjectTypes SpriteObject::getType() const {
        return ObjectTypes::Sprite;
    }

    const std::vector<std::unique_ptr<IObject>> &SpriteObject::getChildren() const {
        return this->_children;
    }

    std::vector<std::unique_ptr<IObject>> &SpriteObject::getChildren() {
        return this->_children;
    }

    const Uniti &SpriteObject::getGame() const {
        return this->_game;
    }

    Uniti &SpriteObject::getGame() {
        return this->_game;
    }

    const Scene &EmptyObject::getScene() const {
        return this->_scene;
    }

    Scene &EmptyObject::getScene() {
        return this->_scene;
    }

    ScriptManager &SpriteObject::getScriptManager() {
        return this->_scriptManager;
    }
}