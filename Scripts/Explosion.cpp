#define IndentWidth 4
//
// Created by youba on 14/10/2023.
//

#include "Explosion.hpp"

#include "Objects.hpp"
#include "Scene.hpp"
#include "Uniti.hpp"

Explosion::Explosion(Uniti::Game::Object &gameObject) : AScript(gameObject) {}

int Explosion::_count = 0;

void Explosion::start() {}

void Explosion::update() {
  if (this->_clock.getMilliSeconds() >= 450) {
    this->getGameObject().getScene().getObjects().remove(
        this->getGameObject().getName());
  }
}

void Explosion::awake(const Json::Value &value) {}

void Explosion::createExplosion(const Uniti::Render::Vector2f &position) {
  auto copy = Uniti::Game::Utils::Objects::find("Explosion");

  if (copy == std::nullopt)
    return;
  Explosion::_count = (Explosion::_count > 1000) ? 0 : Explosion::_count + 1;
  auto newExplosion = std::make_unique<Uniti::Game::Object>(copy.value());
  newExplosion->getTransform().getPosition().setX(position.getX());
  newExplosion->getTransform().getPosition().setY(position.getY());
  newExplosion->setName("Explosion" + std::to_string(Explosion::_count));
  newExplosion->getScriptManager().addScript(
      std::make_unique<Explosion>(*newExplosion), "Explosion");
  Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().add(
      std::move(newExplosion));
}
