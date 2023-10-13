//
// Created by youba on 05/10/2023.
//

#pragma once

#include <json/value.h>
#include "Font.hpp"
#include "Texture.hpp"

namespace Uniti::Game {
    class AssetManager {
    public:
        AssetManager(const Json::Value &assets);
        void loadAssets(const Json::Value &assets);
        const Render::Font &getFont(const std::string &name) const;
        Render::Font &getFont(const std::string &name);
        const Render::Texture &getTexture(const std::string &name) const;
        Render::Texture &getTexture(const std::string &name);
        void addTexture(const Json::Value &params);
        void addTexture(const std::string &path, const std::string &name, bool isSmooth = false, bool isRepeated = false);
        void addTexture(std::unique_ptr<Render::Texture> texture, const std::string &name);
        void addFont(const Json::Value &params);
        void addFont(const std::string &path, const std::string &name);
        bool removeTexture(const std::string &name);
        bool removeFont(const std::string &name);
        void clearTextures();
        void clearFonts();
    private:
        std::map<std::string, std::unique_ptr<Render::Font>> _fonts;
        std::map<std::string, std::unique_ptr<Render::Texture>> _textures;
        std::mutex _mutex;
    };
}
