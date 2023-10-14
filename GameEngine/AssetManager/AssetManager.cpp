//
// Created by youba on 05/10/2023.
//

#include "AssetManager.hpp"

namespace Uniti::Game {
AssetManager::AssetManager(const Json::Value &assets) {
  this->loadAssets(assets);
}

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

const Render::Font &AssetManager::getFont(const std::string &name) const {
  return *this->_fonts.at(name);
}

Render::Font &AssetManager::getFont(const std::string &name) {
  return *this->_fonts.at(name);
}

const Render::Texture &AssetManager::getTexture(const std::string &name) const {
  return *this->_textures.at(name);
}

Render::Texture &AssetManager::getTexture(const std::string &name) {
  return *this->_textures.at(name);
}

void AssetManager::addTexture(const Json::Value &params) {
  const std::string &path = params.get("path", "").asString();
  const std::string &name = params.get("name", "").asString();
  bool isSmooth = params.get("isSmooth", false).asBool();
  bool isRepeated = params.get("isRepeated", false).asBool();
  this->addTexture(path, name, isSmooth, isRepeated);
}

void AssetManager::addTexture(const std::string &path, const std::string &name,
                              bool isSmooth, bool isRepeated) {
  std::unique_ptr<Render::Texture> texture =
      std::make_unique<Render::Texture>(path);
  texture->setSmooth(isSmooth);
  texture->setRepeated(isRepeated);
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_textures[name] = std::move(texture);
}

void AssetManager::addTexture(std::unique_ptr<Render::Texture> texture,
                              const std::string &name) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_textures[name] = std::move(texture);
}

void AssetManager::addFont(const Json::Value &params) {
  const std::string &path = params.get("path", "").asString();
  const std::string &name = params.get("name", "").asString();
  this->addFont(path, name);
}

void AssetManager::addFont(const std::string &path, const std::string &name) {
  std::unique_ptr<Render::Font> font = std::make_unique<Render::Font>(path);
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_fonts[name] = std::move(font);
}

bool AssetManager::removeTexture(const std::string &name) {
  if (!this->_textures.contains(name))
    return false;
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_textures.erase(name);
  return true;
}

bool AssetManager::removeFont(const std::string &name) {
  if (!this->_fonts.contains(name))
    return false;
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_fonts.erase(name);
  return true;
}

void AssetManager::clearTextures() {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_textures.clear();
}

void AssetManager::clearFonts() {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_fonts.clear();
}
} // namespace Uniti::Game