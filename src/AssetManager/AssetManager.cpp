//
// Created by youba on 25/09/2023.
//

#include "AssetManager.hpp"

namespace UnitiGameEngine
{
    AssetManager::AssetManager(Uniti &_game): _game(_game) {}
    
    void AssetManager::loadAssets(const Json::Value &assets) {
        Json::Value textures = assets["textures"];
        Json::Value fonts = assets["fonts"];

        for (int i = 0; i < textures.size(); i++) {
            addTexture(textures[i]);
        }
        for (int i = 0; i < fonts.size(); i++) {
            addFont(fonts[i]);
        }
    }
    
    const sf::Font &AssetManager::getFont(const std::string &name) const {
        return *(_fonts.at(name));
    }
    
    const sf::Texture &AssetManager::getTexture(const std::string &name) const {
        return *(_textures.at(name));
    }

    void AssetManager::addTexture(const Json::Value &params) {
        std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
        
        texture->loadFromFile(params["path"].asString());
        texture->setRepeated(params["isRepeated"].asBool());
        texture->setSmooth(params["isSmooth"].asBool());
        _textures.emplace(params["name"].asString(), texture);
    }

    void AssetManager::addTexture(const std::string &path, const std::string &name, bool isSmooth, bool isRepeated) {
        std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();

        texture->loadFromFile(path);
        texture->setRepeated(isRepeated);
        texture->setSmooth(isSmooth);
        _textures.emplace(name, texture);
    }

    void AssetManager::addTexture(std::unique_ptr<sf::Texture> texture, const std::string &name) {
        _textures.emplace(std::move(texture), name);
    }

    void AssetManager::addFont(const Json::Value &params) {
        std::unique_ptr<sf::Font> font = std::make_unique<sf::Font>();

        font->loadFromFile(params["path"].asString());
        _fonts.emplace(params["name"].asString(), font);
    }

    void AssetManager::addFont(const std::string &path, const std::string &name) {
        std::unique_ptr<sf::Font> font = std::make_unique<sf::Font>();

        font->loadFromFile(path);
        _fonts.emplace(name, font);
    }
    
    bool AssetManager::removeTexture(const std::string &name) {
        if (_textures.count(name)) {
            _textures.erase(name);
            return (true);
        }
        return (false);
    }
    
    bool AssetManager::removeFont(const std::string &name) {
        if (_fonts.count(name)) {
            _fonts.erase(name);
            return (true);
        }
        return (false);
    }
    
    void AssetManager::clearTextures() {
        _textures.clear();
    }

    void AssetManager::clearFonts() {
        _fonts.clear();
    }
}
