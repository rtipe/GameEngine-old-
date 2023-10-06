//
// Created by youba on 05/10/2023.
//

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

// mettre une méthode spécial pour chaque render (comme le getFont() pour la sfml)
// ou si le texte n'a pas besoin de font, se servir de font peut stocker les paramètres comme le chemin...
namespace Uniti::Render {
    class Font {
    public:
        Font(const std::string &path);
        void setSmooth(bool smooth);
        const std::string &getPath() const;
        bool isSmooth() const;
        sf::Font &getFontAsset();
    };
}
