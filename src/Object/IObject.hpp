//
// Created by youba on 25/09/2023.
//

#pragma once

#include <string>
#include <vector>
#include "Transform/Transform.hpp"
#include "../Scene/Scene.hpp"
#include "../Script/ScriptManager.hpp"
#include "../UnitiGame.hpp"

namespace UnitiGameEngine {
    enum class ObjectTypes {
        Empty,
        Sprite,
        Text
    };
    class IObject {
        public:
            virtual ~IObject() = default;
            virtual void update() = 0;
            virtual void display() = 0;
            virtual const std::string &getName() const = 0;
            virtual void setEnable(bool value) = 0;
            virtual bool isDisabled() const = 0;
            virtual const Transform &getTransform() const = 0;
            virtual Transform &getTransform() = 0;
            virtual ObjectTypes getType() const = 0;
            virtual const std::vector<std::unique_ptr<IObject>> &getChildren() const = 0;
            virtual std::vector<std::unique_ptr<IObject>> &getChildren() = 0;
            virtual const Uniti &getGame() const = 0;
            virtual Uniti &getGame() = 0;
            virtual ScriptManager &getScriptManager() = 0;
    };
}
