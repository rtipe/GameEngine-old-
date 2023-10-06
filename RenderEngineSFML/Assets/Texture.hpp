//
// Created by youba on 05/10/2023.
//

#pragma once


#include <string>
#include <SFML/Graphics.hpp>
#include <mutex>

namespace Uniti::Render {
    class Texture {
    public:
        Texture(const std::string &path);
        void setSmooth(bool smooth);
        void setRepeated(bool repeated);
        const std::string &getPath() const;
        bool isSmooth() const;
        bool isRepeated() const;
        sf::Texture &getTexture();
    private:
        sf::Texture _texture;
        std::string _path;
        std::mutex _mutex;
    };
}
