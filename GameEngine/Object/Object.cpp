//
// Created by youba on 05/10/2023.
//

#include "Object.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "Uniti.hpp"

namespace Uniti::Game {
    Object::Object(Object &object):
    _scene(object.getScene()),
    _collision(object.getCollision().getBox()),
    _children(object.getChildren().getObjects()),
    _transform(object.getTransform()),
    _layer(object.getLayer()),
    _name(object.getName()),
    _movement(*this),
    _scriptManager(object.getScriptManager().getData()) {
        if (object.hasPrintable()) {
            if (object.getPrintable().getTypeName() == "sprite") {
                this->_printable = std::make_unique<Render::Sprite>(dynamic_cast<Render::Sprite &>(object.getPrintable()));
            }
            if (object.getPrintable().getTypeName() == "text") {
                this->_printable = std::make_unique<Render::Text>(dynamic_cast<Render::Text &>(object.getPrintable()));
            }
        }
        this->_scriptManager.start();
    }

    Object::Object(const Json::Value &value, Scene &scene):
    _scene(scene),
    _collision(value["collision"]),
    _children(value["children"], scene),
    _transform(value["transform"]),
    _layer(value.get("layer", "").asString()),
    _name(value.get("name", "").asString()),
    _movement(*this),
    _scriptManager(value["scripts"]) {
        this->setPrintable(value);
        this->_scriptManager.start();
    }

    Object::Object(const std::string &name, Scene &scene):
    _scene(scene),
    _children({}),
    _name(name),
    _movement(*this),
    _scriptManager({}) { }

    void Object::update() {
        if (!this->_isEnable)
            return;
        this->_movement.getClock().restart();
        this->_scriptManager.update();
        this->_movement.update();
        this->_children.update();
        if (this->_printable)
            this->_printable->display(Uniti::Game::Core::getWindow());
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
            this->_printable = std::make_unique<Render::Sprite>(this->_scene.getAssetManager().getTexture(textureName));
        }
        if (type == "text") {
            const std::string &fontName = value.get("font", "").asString();
            this->_printable = std::make_unique<Render::Text>(this->_scene.getAssetManager().getFont(fontName));
        }
        if (type == "empty")
            this->_printable = nullptr;
    }

    bool Object::hasPrintable() const {
        return this->_printable == nullptr;
    }
}