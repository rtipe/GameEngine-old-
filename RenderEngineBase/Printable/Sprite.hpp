//
// Created by youba on 05/10/2023.
//

#pragma once


#include "IPrintable.hpp"
#include "Texture.hpp"
#include "Box.hpp"
#include "Color.hpp"

namespace Uniti::Render {
    class Sprite : public IPrintable {
    public:
        Sprite(Texture &texture);
        void setTexture(Texture &texture);
        void setTextureRect(const Box &rect);
        void setColor(const Color &color);
        void display(Window &window) override;
        const std::string &getTypeName() const override;
        const Vector3f &getPosition() const override;
        const Vector2f &getScale() const override;
        const float getRotation() const override;
        void setPosition(const Vector3f &position) override;
        void setScale(const Vector2f &scale) override;
        void setRotation(float rotation) override;
        void setOrigin(const Vector2f &origin) override;
    };
}
