//
// Created by youba on 26/09/2023.
//

#include "TextObject.hpp"

namespace UnitiGameEngine {

    TextObject::TextObject(Uniti &game, const Json::Value &values): _game(game) {

        this->_scriptManager.start();
    }

    void TextObject::update() {
        if (!this->_isEnabled) return;
        this->_scriptManager.update();
        this->_game.getSceneManager().getDisplayer().add(this);
        for (const auto &child : this->_children)
            child->update();
    }

    void TextObject::display() {
        this->_text.setPosition(this->_transform.position.x, this->_transform.position.y);
        this->_text.setRotation(this->_transform.rotation.angle);
        this->_text.setScale(this->_transform.scale.x, this->_transform.scale.y);
        this->_game.getWindow().draw(this->_text);
    }

    const std::string &TextObject::getName() const {
        return this->_name;
    }

    void TextObject::setEnable(bool value) {
        this->_isEnabled = value;
    }

    bool TextObject::isDisabled() const {
        return !this->_isEnabled;
    }

    const Transform &TextObject::getTransform() const {
        return this->_transform;
    }

    Transform &TextObject::getTransform() {
        return this->_transform;
    }

    ObjectTypes TextObject::getType() const {
        return ObjectTypes::Text;
    }

    const std::vector<std::unique_ptr<IObject>> &TextObject::getChildren() const {
        return this->_children;
    }

    std::vector<std::unique_ptr<IObject>> &TextObject::getChildren() {
        return this->_children;
    }

    const Uniti &TextObject::getGame() const {
        return this->_game;
    }

    Uniti &TextObject::getGame() {
        return this->_game;
    }

    ScriptManager &TextObject::getScriptManager() {
        return this->_scriptManager;
    }
}
