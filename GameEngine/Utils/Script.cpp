//
// Created by youba on 05/10/2023.
//

#include "Object.hpp"
#include "Script.hpp"

namespace Uniti::Game::Utils {
    std::optional<std::reference_wrapper<IScript>> Script::find(Object &object, const std::string &name) {
        if (object.getScriptManager().contentScript(name))
            return object.getScriptManager().getScript(name);
        return std::nullopt;
    }

    template<typename SCRIPT>
    std::optional<std::reference_wrapper<SCRIPT>> Script::find_type(Object &object, const std::string &name) {
        auto script = find(object, name);
        try {
            SCRIPT &finalScript = dynamic_cast<SCRIPT &>(script->get());
            return finalScript;
        } catch (const std::bad_cast &e) {
            return std::nullopt;
        }
    }
}