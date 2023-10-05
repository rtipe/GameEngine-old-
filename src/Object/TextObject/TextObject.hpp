//
// Created by youba on 26/09/2023.
//

#pragma once

#include <SFML/Graphics/Text.hpp>
#include "../IObject.hpp"

namespace UnitiGameEngine {
    class TextObject: public IObject {
        public:
            TextObject(Scene &scene, const Json::Value &values);
            TextObject(Scene &scene);
            TextObject(IObject &object, Scene &scene);
            void update() override;
            void display() override;
            void setName(std::string name) override;
            const std::string &getName() const override;
            void setEnable(bool value) override;
            bool isDisabled() const override;
            const Transform &getTransform() const override;
            Transform &getTransform() override;
            ObjectTypes getType() const override;
            const std::vector<std::unique_ptr<IObject>> &getChildren() const override;
            std::vector<std::unique_ptr<IObject>> &getChildren() override;
            const Scene &getScene() const override;
            Scene &getScene() override;
            Json::Value &getScripts() override;
            ScriptManager &getScriptManager() override;
            const std::string &getString() const;
            void setString(const std::string &value);
        private:
            ScriptManager _scriptManager;
            Transform _transform;
            Json::Value _scripts;
            std::vector<std::unique_ptr<IObject>> _children;
            Scene &_scene;
            bool _isEnabled = true;
            std::string _name;
            sf::Text _text;
            std::string _textString;
    };
}
