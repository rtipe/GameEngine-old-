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
        Sprite(Sprite &sprite);
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
    private:
        std::mutex _mutex;
        sf::Sprite _sprite;
        Texture &_texture;
        const std::string _type = "sprite";
        Vector3f _position;
        Vector2f _scale;
        Vector2f _origin;
        float _rotation = 0;
    };
}
