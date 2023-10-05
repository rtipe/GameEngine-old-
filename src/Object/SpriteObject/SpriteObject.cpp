//
// Created by youba on 26/09/2023.
//

#include "SpriteObject.hpp"
#include "../TextObject/TextObject.hpp"
#include "../EmptyObject/EmptyObject.hpp"
#include "../../UnitiGame.hpp"

namespace UnitiGameEngine {
    SpriteObject::SpriteObject(Scene &scene, const Json::Value &values): _scene(scene) {
        const Json::Value scripts = values["scripts"];

        if (values.isMember("name"))
            this->_name = values["name"].asString();
        if (values.isMember("position")) {
            this->_transform.position.x = values["position"]["x"].asFloat();
            this->_transform.position.y = values["position"]["y"].asFloat();
            this->_transform.position.z = values["position"]["z"].asFloat();
        }
        if (values.isMember("rotation")) {
            this->_transform.rotation.angle = values["rotation"].asFloat();
        }
        if (values.isMember("scale")) {
            this->_transform.scale.x = values["scale"]["x"].asFloat();
            this->_transform.scale.y = values["scale"]["y"].asFloat();
        }
        if (values.isMember("textureName")) {
            this->_textureName = values["textureName"].asString();
            this->_sprite.setTexture(this->_scene.getAssetManager().getTexture(values["textureName"].asString()));
        }
        for (const auto &child : values["children"]) {
            if (child["type"].asString() == "sprite") {
                this->_children.push_back(std::make_unique<SpriteObject>(scene, child));
            } else if (child["type"].asString() == "text") {
                this->_children.push_back(std::make_unique<TextObject>(scene, child));
            } else if (child["type"].asString() == "empty") {
                this->_children.push_back(std::make_unique<EmptyObject>(scene, child));
            } else {
                throw std::runtime_error("Unknown object type");
            }
        }
        this->_name = values["name"].asString();
        this->_scripts = scripts;
        for (int i = 0; i < scripts.size(); i++) {
            auto name = scripts[i]["name"].asString();
            this->_scriptManager.addScript(Uniti::getInstance().getScriptFactory().createScript(name, *this), name);
            this->_scriptManager.getScript(name).awake(scripts[i]);
        }
        this->_scriptManager.start();
    }

    SpriteObject::SpriteObject(Scene &scene): _scene(scene) {
        Transform transform;

        transform.position.x = 0;
        transform.position.y = 0;
        transform.position.z = 0;
        transform.rotation = 0;
        transform.scale.x = 0;
        transform.scale.y = 0;

        this->_transform = transform;
    }

    SpriteObject::SpriteObject(IObject &object, Scene &scene): _scene(scene) {
        SpriteObject &test = dynamic_cast<SpriteObject &>(object);

        this->_transform.position.x = test.getTransform().position.x;
        this->_transform.position.y = test.getTransform().position.y;
        this->_transform.position.z = test.getTransform().position.z;
        this->_transform.rotation.angle = test.getTransform().rotation.angle;
        this->_transform.scale.x = test.getTransform().scale.x;
        this->_transform.scale.y = test.getTransform().scale.y;
        this->_sprite.setTexture(this->_scene.getAssetManager().getTexture(test.getTextureName()));
        this->_textureName = test.getTextureName();
        this->_name = test.getName();

        for (int i = 0; i < test.getChildren().size(); i++) {
            const UnitiGameEngine::ObjectTypes type = test.getChildren()[i].get()->getType();

            if (type == UnitiGameEngine::ObjectTypes::Empty) {
                this->_children.push_back(std::make_unique<UnitiGameEngine::EmptyObject>(*test.getChildren()[i], this->_scene));
            } else if (type == UnitiGameEngine::ObjectTypes::Sprite) {
                this->_children.push_back(std::make_unique<UnitiGameEngine::SpriteObject>(*test.getChildren()[i], this->_scene));
            } else if (type == UnitiGameEngine::ObjectTypes::Text) {
                this->_children.push_back(std::make_unique<UnitiGameEngine::TextObject>(*test.getChildren()[i], this->_scene));
            } else {
                //TODO error
            }
        }
        for (int i = 0; i < test.getScripts().size(); i++) {
            auto name = test.getScripts()[i]["name"].asString();
            this->_scriptManager.addScript(Uniti::getInstance().getScriptFactory().createScript(name, *this), name);
            this->_scriptManager.getScript(name).awake(test.getScripts()[i]);
        }
        this->_scriptManager.start();
    }

    void SpriteObject::update() {
        if (!this->_isEnabled) return;
        this->_scriptManager.update();
        Uniti::getInstance().getSceneManager().getDisplayer().add(*this);
        for (const auto &child : this->_children)
            child->update();
    }

    void SpriteObject::display() {
        this->_sprite.setPosition(this->_transform.position.x, this->_transform.position.y);
        this->_sprite.setRotation(this->_transform.rotation.angle);
        this->_sprite.setScale(this->_transform.scale.x, this->_transform.scale.y);
        Uniti::getInstance().getWindow().draw(this->_sprite);
    }

    void SpriteObject::setName(std::string name) {
        this->_name = name;
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

    const Scene &SpriteObject::getScene() const {
        return this->_scene;
    }

    Scene &SpriteObject::getScene() {
        return this->_scene;
    }

    Json::Value &SpriteObject::getScripts() {
        return this->_scripts;
    }

    ScriptManager &SpriteObject::getScriptManager() {
        return this->_scriptManager;
    }

    const std::string &SpriteObject::getTextureName() {
        return this->_textureName;
    }
}