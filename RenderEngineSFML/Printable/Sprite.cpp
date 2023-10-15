//
// Created by youba on 05/10/2023.
//

#include "Sprite.hpp"

namespace Uniti::Render {
    Sprite::Sprite(Texture &texture) : _texture(texture)
    {
        this->_sprite.setTexture(texture.getTexture());
    }

    void Sprite::setTexture(Texture &texture)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_texture = texture;
    }

    void Sprite::setTextureRect(const Box &rect)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        sf::Rect<int> box;

        box.left   = rect.getPosition().getX();
        box.top    = rect.getPosition().getY();
        box.width  = rect.getDimension().getX();
        box.height = rect.getDimension().getY();
        this->_sprite.setTextureRect(box);
    }

    void Sprite::setColor(const Color &color)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_sprite.setColor(sf::Color(color.getR(), color.getG(), color.getB()));
    }

    void Sprite::display(Window &window)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_sprite.setPosition(this->_position.getX(), this->_position.getY());
        this->_sprite.setRotation(this->_rotation);
        this->_sprite.setOrigin(this->_origin.getX(), this->_origin.getY());
        this->_sprite.setScale(this->_scale.getX(), this->_scale.getY());
        window.getRenderWindow().draw(this->_sprite);
    }

    const std::string &Sprite::getTypeName() const
    {
        return this->_type;
    }

    const Vector3f &Sprite::getPosition() const
    {
        return this->_position;
    }

    const Vector2f &Sprite::getScale() const
    {
        return this->_scale;
    }

    const float Sprite::getRotation() const
    {
        return this->_rotation;
    }

    void Sprite::setPosition(const Vector3f &position)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_position = position;
    }

    void Sprite::setScale(const Vector2f &scale)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_scale = scale;
    }

    void Sprite::setRotation(float rotation)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_rotation = rotation;
    }

    void Sprite::setOrigin(const Vector2f &origin)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_origin = origin;
    }

    Sprite::Sprite(Sprite &sprite) : _texture(sprite._texture)
    {
        this->_sprite   = sprite._sprite;
        this->_position = sprite._position;
        this->_scale    = sprite._scale;
        this->_origin   = sprite._origin;
        this->_rotation = sprite._rotation;
    }
} // namespace Uniti::Render