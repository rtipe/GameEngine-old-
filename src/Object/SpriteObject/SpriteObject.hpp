//
// Created by youba on 26/09/2023.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "../IObject.hpp"

namespace UnitiGameEngine {
    class SpriteObject: IObject {
    public:
        SpriteObject(Uniti &game, const Json::Value &values);
        void update() override;
        void display() override;
        const std::string &getName() const override;
        void setEnable(bool value) override;
        bool isDisabled() const override;
        const Transform &getTransform() const override;
        Transform &getTransform() override;
        ObjectTypes getType() const override;
        const std::vector<std::unique_ptr<IObject>> &getChildren() const override;
        std::vector<std::unique_ptr<IObject>> &getChildren() override;
        const Uniti &getGame() const override;
        Uniti &getGame() override;
        ScriptManager &getScriptManager() override;
    private:
        ScriptManager _scriptManager;
        Transform _transform;
        std::vector<std::unique_ptr<IObject>> _children;
        Uniti &_game;
        bool _isEnabled;
        std::string _name;
        sf::Sprite _sprite;
    };
}
