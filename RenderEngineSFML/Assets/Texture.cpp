#define IndentWidth 4
//
// Created by youba on 05/10/2023.
//

#include "Texture.hpp"

namespace Uniti::Render {
Texture::Texture(const std::string &path) : _path(path) {
  this->_texture.loadFromFile(path);
}

void Texture::setSmooth(bool smooth) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_texture.setSmooth(smooth);
}

void Texture::setRepeated(bool repeated) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_texture.setRepeated(repeated);
}

const std::string &Texture::getPath() const { return this->_path; }

bool Texture::isSmooth() const { return this->_texture.isSmooth(); }

bool Texture::isRepeated() const { return this->_texture.isRepeated(); }

sf::Texture &Texture::getTexture() { return this->_texture; }
} // namespace Uniti::Render