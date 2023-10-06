//
// Created by youba on 05/10/2023.
//

#pragma once


#include <string>
#include "Font.hpp"
#include "IPrintable.hpp"
#include "Color.hpp"

namespace Uniti::Render {
    class Text : public IPrintable {
    public:
        enum TextStyle {
            BOLD,
            ITALIC,
            REGULAR
        };
        Text(Font &font);
        void setString(const std::string &value);
        void setFont(Font &font);
        void setCharacterSize(unsigned int size);
        void setStyle(TextStyle style);
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
        sf::Text _text;
        Font &_font;
        const std::string _type = "text";
        Vector3f _position;
        Vector2f _scale;
        Vector2f _origin;
        float _rotation;
    };
}