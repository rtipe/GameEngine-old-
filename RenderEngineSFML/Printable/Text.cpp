//
// Created by youba on 05/10/2023.
//

#include "Text.hpp"

namespace Uniti::Render {
    Text::Text(Font &font): _font(font) {
        this->_text.setFont(font.getFontAsset());
    }

    void Text::setString(const std::string &value) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_text.setString(value);
    }

    void Text::setFont(Font &font) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_font = font;
        this->_text.setFont(font.getFontAsset());
    }

    void Text::setCharacterSize(unsigned int size) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_text.setCharacterSize(size);
    }

    void Text::setStyle(Text::TextStyle style) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        sf::Text::Style sfStyle;
        switch (style) {
            case REGULAR:
                sfStyle = sf::Text::Regular;
                break;
            case BOLD:
                sfStyle = sf::Text::Bold;
                break;
            case ITALIC:
                sfStyle = sf::Text::Italic;
                break;
            default:
                sfStyle = sf::Text::Regular;
                break;
        }
        this->_text.setStyle(sfStyle);
    }

    void Text::setColor(const Color &color) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_text.setFillColor({
            static_cast<sf::Uint8>(color.getR()),
            static_cast<sf::Uint8>(color.getG()),
            static_cast<sf::Uint8>(color.getB())}
        );
    }

    void Text::display(Window &window) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_text.setPosition(this->_position.getX(), this->_position.getY());
        this->_text.setRotation(this->_rotation);
        this->_text.setOrigin(this->_origin.getX(), this->_origin.getY());
        this->_text.setScale(this->_scale.getX(), this->_scale.getY());
        window.getRenderWindow().draw(this->_text);
    }

    const std::string &Text::getTypeName() const {
        return this->_type;
    }

    const Vector3f &Text::getPosition() const {
        return this->_position;
    }

    const Vector2f &Text::getScale() const {
        return this->_scale;
    }

    const float Text::getRotation() const {
        return this->_rotation;
    }

    void Text::setPosition(const Vector3f &position) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_position = position;
    }

    void Text::setScale(const Vector2f &scale) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_scale = scale;
    }

    void Text::setRotation(float rotation) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_rotation = rotation;
    }

    void Text::setOrigin(const Vector2f &origin) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_origin = origin;
    }

    Text::Text(Text &text): _font(text._font) {
        this->_text = text._text;
        this->_scale = text._scale;
        this->_position = text._position;
        this->_rotation = text._rotation;
        this->_origin = text._origin;
    }
}