#define IndentWidth 4
//
// Created by youba on 05/10/2023.
//

#include "ScriptFactory.hpp"

namespace Uniti::Game {
std::unique_ptr<IScript> ScriptFactory::createScript(const std::string &name,
                                                     Object &object) {
  auto it = this->creators.find(name);

  if (it == this->creators.end())
    throw std::invalid_argument("Invalid type");
  return it->second(object);
}
} // namespace Uniti::Game