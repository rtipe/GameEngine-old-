//
// Created by youba on 05/10/2023.
//

#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <mutex>

namespace Uniti::Render {
    class Font {
    public:
        Font(const std::string &path);
        void setSmooth(bool smooth);
        const std::string &getPath() const;
        bool isSmooth() const;
        sf::Font &getFontAsset();
    private:
        sf::Font _font;
        std::string _path;
        std::mutex _mutex;
    };
}
