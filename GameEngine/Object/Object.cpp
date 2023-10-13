//
// Created by youba on 05/10/2023.
//

#include <iostream>
#include "Object.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "Uniti.hpp"
#include "Scene.hpp"

namespace Uniti::Game {

    Object::Object(Object &object):
    _scene(object.getScene()),
    _children(object.getChildren().getObjects()),
    _transform(object.getTransform()),
    _collision(object.getCollision().getBox(), _transform),
    _layer(object.getLayer()),
    _name(object.getName()),
    _movement(*this),
    _scriptManager(object.getScriptManager().getData(), *this) {
        if (object.hasPrintable()) {
            if (object.getPrintable().getTypeName() == "sprite") {
                this->_printable = std::make_unique<Render::Sprite>(dynamic_cast<Render::Sprite &>(object.getPrintable()));
            }
            if (object.getPrintable().getTypeName() == "text") {
                this->_printable = std::make_unique<Render::Text>(dynamic_cast<Render::Text &>(object.getPrintable()));
            }
        }
    }

    Object::Object(const Json::Value &value, Scene &scene):
    _scene(scene),
    _children(value["children"], scene),
    _transform(value["transform"]),
    _collision(value["collision"], _transform),
    _layer(value.get("layer", "").asString()),
    _name(value.get("name", "").asString()),
    _movement(*this),
    _scriptManager(value["scripts"], *this),
    _data(value) {
        this->setPrintable(value);
    }

    Object::Object(const std::string &name, Scene &scene):
    _scene(scene),
    _children({}),
    _name(name),
    _transform(),
    _collision(_transform),
    _movement(*this),
    _scriptManager({}, *this) { }

    void Object::update() {
        if (!this->_isEnable)
            return;
        this->_scriptManager.update();
        this->_movement.update();
        this->_movement.getClock().restart();
        this->_children.update();
        if (this->_printable) {
            this->_printable->setScale(this->_transform.getScale());
            this->_printable->setOrigin(this->_transform.getOrigin());
            this->_printable->setRotation(this->_transform.getRotation());
            this->_printable->setPosition(this->_transform.getPosition());
            Uniti::Game::Core::getWindow().print(*this->_printable);
        }
    }

    void Object::setName(const std::string &name) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_name = name;
    }

    const std::string &Object::getName() const {
        return this->_name;
    }

    void Object::setEnable(bool value) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_isEnable = value;
        if (this->_isEnable)
            this->_scriptManager.emitEvent("onEnable", {});
        else
            this->_scriptManager.emitEvent("onDisable", {});
    }

    bool Object::isEnabled() const {
        return this->_isEnable;
    }

    const Transform &Object::getTransform() const {
        return this->_transform;
    }

    Transform &Object::getTransform() {
        return this->_transform;
    }

    const ObjectManager &Object::getChildren() const {
        return this->_children;
    }

    ObjectManager &Object::getChildren() {
        return this->_children;
    }

    const Scene &Object::getScene() const {
        return this->_scene;
    }

    Scene &Object::getScene() {
        return this->_scene;
    }

    const ScriptManager &Object::getScriptManager() const {
        return this->_scriptManager;
    }

    ScriptManager &Object::getScriptManager() {
        return this->_scriptManager;
    }

    const Movement &Object::getMovement() const {
        return this->_movement;
    }

    Movement &Object::getMovement() {
        return this->_movement;
    }

    const Collision &Object::getCollision() const {
        return this->_collision;
    }

    Collision &Object::getCollision() {
        return this->_collision;
    }

    const std::string &Object::getLayer() const {
        return this->_layer;
    }

    void Object::setLayer(const std::string &layer) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_layer = layer;
    }

    const Render::IPrintable &Object::getPrintable() const {
        return *this->_printable;
    }

    Render::IPrintable &Object::getPrintable() {
        return *this->_printable;
    }

    void Object::setPrintable(const Json::Value &value) {
        const std::string &type = value.get("type", "empty").asString();

        if (type == "sprite") {
            const std::string &textureName = value.get("texture", "").asString();
            std::unique_ptr<Render::Sprite> sprite = std::make_unique<Render::Sprite>(this->_scene.getAssetManager().getTexture(textureName));
            if (value.isMember("textureRect"))
                sprite->setTextureRect(value["textureRect"]);
            this->_printable = std::move(sprite);
        }
        if (type == "text") {
            const std::string &fontName = value.get("font", "").asString();
            std::unique_ptr<Render::Text> text = std::make_unique<Render::Text>(this->_scene.getAssetManager().getFont(fontName));
            text->setString(value.get("text", "").asString());
            text->setColor(value["color"]);
            const std::string &style = value.get("style", "regular").asString();
            if (style == "regular")
                text->setStyle(Uniti::Render::Text::REGULAR);
            if (style == "bold")
                text->setStyle(Uniti::Render::Text::BOLD);
            if (style == "italic")
                text->setStyle(Uniti::Render::Text::ITALIC);
            text->setCharacterSize(value.get("size", 24).asInt());
            this->_printable = std::move(text);
        }
        if (type == "empty")
            this->_printable = nullptr;
    }

    bool Object::hasPrintable() const {
        return this->_printable != nullptr;
    }

    const Json::Value &Object::getData() const {
        return this->_data;
    }

    std::string &Object::getName() {
        return this->_name;
    }
}