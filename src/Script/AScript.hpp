//
// Created by youba on 25/09/2023.
//

#pragma once

#include "IScript.hpp"
#include "../UnitiGame.hpp"

namespace UnitiGameEngine {
    class AScript : IScript {
        public:
            AScript(IObject &gameObject): _gameObject(gameObject) {}
        private:
            IObject &_gameObject;
    };
}
