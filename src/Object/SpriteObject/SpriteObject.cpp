//
// Created by youba on 26/09/2023.
//

#include "SpriteObject.hpp"

namespace UnitiGameEngine {

    SpriteObject::SpriteObject(Uniti &game, const Json::Value &values): _game(game) {

    }

    void SpriteObject::update() {
        if (!this->_isEnabled) return;
        this->_scriptManager.update();
        this->_game.getSceneManager().getDisplayer().add(this);
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

    ScriptManager &SpriteObject::getScriptManager() {
        return this->_scriptManager;
    }
}