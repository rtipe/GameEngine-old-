//
// Created by youba on 26/09/2023.
//

#include "TextObject.hpp"
#include "../SpriteObject/SpriteObject.hpp"
#include "../EmptyObject/EmptyObject.hpp"
#include "../../UnitiGame.hpp"

namespace UnitiGameEngine {

    TextObject::TextObject(Scene &scene, const Json::Value &values): _scene(scene) {
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
        if (values.isMember("text")) {
            this->_text.setString(values["text"].asString());
            this->_textString = values["text"].asString();
        }
        if (values.isMember("fontName")) {
            this->_text.setFont(scene.getAssetManager().getFont(values["fontName"].asString()));
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
        for (int i = 0; i < scripts.size(); i++) {
            auto name = scripts[i]["name"].asString();
            this->_scriptManager.addScript(Uniti::getInstance().getScriptFactory().createScript(name, *this), name);
            this->_scriptManager.getScript(name).awake(scripts[i]);
        }
        this->_scriptManager.start();
    }

    void TextObject::update() {
        if (!this->_isEnabled) return;
        this->_scriptManager.update();
        Uniti::getInstance().getSceneManager().getDisplayer().add(*this);
        for (const auto &child : this->_children)
            child->update();
    }

    void TextObject::display() {
        this->_text.setPosition(this->_transform.position.x, this->_transform.position.y);
        this->_text.setRotation(this->_transform.rotation.angle);
        this->_text.setScale(this->_transform.scale.x, this->_transform.scale.y);
        Uniti::getInstance().getWindow().draw(this->_text);
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

    const Scene &TextObject::getScene() const {
        return this->_scene;
    }

    Scene &TextObject::getScene() {
        return this->_scene;
    }

    ScriptManager &TextObject::getScriptManager() {
        return this->_scriptManager;
    }

    const std::string &TextObject::getString() const {
        return this->_textString;
    }

    void TextObject::setString(const std::string &value) {
        this->_textString = value;
    }
}
