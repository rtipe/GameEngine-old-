//
// Created by youba on 25/09/2023.
//

#pragma once

#include "IScript.hpp"
#include "../UnitiGame.hpp"

namespace UnitiGameEngine {
    class AScript : public IScript {
        protected:
            AScript(IObject &gameObject): _gameObject(gameObject) {}
            IObject &_gameObject;
    };
}
