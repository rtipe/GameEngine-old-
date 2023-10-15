//
// Created by youba on 13/10/2023.
//

#include "Timer.hpp"
#include "Text.hpp"

Timer::Timer(Uniti::Game::Object &gameObject) : AScript(gameObject)
{
}

void Timer::start()
{
}

void Timer::update()
{
    if (!this->getGameObject().hasPrintable()
        || this->getGameObject().getPrintable().getTypeName() != "text")
        return;
    Uniti::Render::Text &text = dynamic_cast<Uniti::Render::Text &>(this->getGameObject().getPrintable());

    text.setString(std::to_string(this->_clock.getSeconds()) + " Seconds");
}

void Timer::awake(const Json::Value &value)
{
}
