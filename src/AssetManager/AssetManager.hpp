//
// Created by youba on 25/09/2023.
//

#pragma once

#include <SFML/Graphics/Font.hpp>
#include "../UnitiGame.hpp"

namespace UnitiGameEngine {
    class AssetManager {
        public:
            AssetManager(Uniti &_game);
            void loadAssets(const Json::Value &assets);
            const sf::Font &getFont(const std::string &name) const;
            const sf::Texture &getTexture(const std::string &name) const;
            void addTexture(const std::string &path, const std::string &name);
            void addTexture(std::unique_ptr<sf::Texture> texture, const std::string &name);
            void addFont(const std::string &path, const std::string &name);
            bool removeTexture(const std::string &name);
            bool removeFont(const std::string &name);
            void clearTextures();
            void clearFonts();
        private:
            Uniti &_game;
            std::vector<std::unique_ptr<sf::Font>> _fonts;
            std::vector<std::unique_ptr<sf::Texture>> _textures;
    };
}