#include "LiveScript.hpp"

#include "Uniti.hpp"

LiveScript::LiveScript(Uniti::Game::Object &gameObject) : AScript(gameObject) {}

void LiveScript::start() {
  this->getEvent().addEvent("addHealth", [this](const Json::Value &eventData) {
    float healthToAdd = eventData.get("amount", 10.0).asFloat();
    this->_life += healthToAdd;
  });

  this->getEvent().addEvent(
      "removeHealth", [this](const Json::Value &eventData) {
        float healthToRemove = eventData.get("amount", 10.0).asFloat();
        this->_life -= healthToRemove;
      });
}

void LiveScript::update() {
  if (this->_life <= 0) {
    Uniti::Game::Core::getSceneManager()
        .getCurrentScene()
        .getObjects()
        .emitEvent("playerDie", this->getGameObject().getName());
  }
}

void LiveScript::awake(const Json::Value &value) {
  this->_life = value.get("life", 100).asFloat();
}
