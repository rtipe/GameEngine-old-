//
// Created by youba on 05/10/2023.
//

#pragma once


#include <string>

// mettre une méthode spécial pour chaque render (comme le getTexture() pour la sfml)
// ou si sprite n'a pas besoin de texture, se servir de texture peut stocker les paramètres comme le chemin, smooth...
namespace Uniti::Render {
    class Texture {
    public:
        Texture(const std::string &path);
        void setSmooth(bool smooth);
        void setRepeated(bool repeated);
        const std::string &getPath() const;
        bool isSmooth() const;
        bool isRepeated() const;
    };
}
