//
// Created by youba on 05/10/2023.
//

#include "Font.hpp"

namespace Uniti::Render {
    Font::Font(const std::string &path) {
        this->_font.loadFromFile(path);
    }

    void Font::setSmooth(bool smooth) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_font.setSmooth(smooth);
    }

    const std::string &Font::getPath() const {
        return this->_path;
    }

    bool Font::isSmooth() const {
        return this->_font.isSmooth();
    }

    sf::Font &Font::getFontAsset() {
        return this->_font;
    }
}