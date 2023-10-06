//
// Created by youba on 05/10/2023.
//

#pragma once

#include "IScript.hpp"

namespace Uniti::Game {
    class AScript : public IScript {
    protected:
        AScript(Object &object): _gameObject(object) {}
        const Object &getGameObject() const override;
        Object &getGameObject() override;
        const Event &getEvent() const override;
        Event &getEvent() override;
    private:
        Object &_gameObject;
        Event _event;
    };
}
