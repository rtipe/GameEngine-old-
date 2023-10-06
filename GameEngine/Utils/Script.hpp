//
// Created by youba on 05/10/2023.
//

#pragma once


#include "IScript.hpp"

namespace Uniti::Game::Utils {
    class Script {
        static IScript &find(const std::string &name);
        template<typename SCRIPT>
        static SCRIPT &find(const std::string &name);
    };
}
