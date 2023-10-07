//
// Created by youba on 05/10/2023.
//

#pragma once


#include "IScript.hpp"

namespace Uniti::Game::Utils {
    class Script {
        static std::optional<std::reference_wrapper<IScript>> find(Object &object, const std::string &name);
        template<typename SCRIPT>
        static std::optional<std::reference_wrapper<SCRIPT>> find_type(Object &object, const std::string &name);
    };
}
