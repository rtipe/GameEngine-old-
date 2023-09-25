//
// Created by youba on 25/09/2023.
//

#pragma once

#include "IScript.hpp"
#include "../UnitiGame.hpp"

namespace UnitiGameEngine {
    class AScript : IScript {
        public:
            AScript(Uniti &game, IObject &gameObject): _game(game), _gameObject(gameObject) {}
        private:
            Uniti &_game;
            IObject &_gameObject;
    };
}
