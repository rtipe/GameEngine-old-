//
// Created by youba on 05/10/2023.
//

#include "Font.hpp"

namespace Uniti::Render {
    Font::Font(const std::string &path) {
        this->_font.loadFromFile(path);
    }

    const std::string &Font::getPath() const {
        return this->_path;
    }

    sf::Font &Font::getFontAsset() {
        return this->_font;
    }
}