//
// Created by youba on 05/10/2023.
//

#pragma once

#include <string>
#include "Window.hpp"
#include "Vector3f.hpp"
#include "Vector2f.hpp"

namespace Uniti::Render {
    class IPrintable {
    public:
        virtual void display(Window &window) = 0;
        virtual const std::string &getTypeName() const = 0;
        virtual const Vector3f &getPosition() const = 0;
        virtual const Vector2f &getScale() const = 0;
        virtual const float getRotation() const = 0;
        virtual void setPosition(const Vector3f &position) = 0;
        virtual void setScale(const Vector2f &scale) = 0;
        virtual void setRotation(float rotation) = 0;
        virtual void setOrigin(const Vector2f &origin) = 0;
    };
}