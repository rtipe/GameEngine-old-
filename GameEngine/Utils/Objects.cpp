//
// Created by youba on 05/10/2023.
//

#include "Objects.hpp"

#include <iostream>

#include "Uniti.hpp"

namespace Uniti::Game::Utils {
std::optional<std::reference_wrapper<Object>> Objects::find(
    const std::string &name, bool recursive) {
  auto global = find(
      name, Uniti::Game::Core::getSceneManager().getGlobalScene(), recursive);
  if (global) return global;
  auto current = find(
      name, Uniti::Game::Core::getSceneManager().getCurrentScene(), recursive);
  if (current) return current;
  return std::nullopt;
}

std::optional<std::reference_wrapper<Object>> Objects::find(
    const std::string &name, const Scene &scene, bool recursive) {
  auto object = find(name, scene.getObjects(), recursive);
  if (object) return object;
  return std::nullopt;
}

std::optional<std::reference_wrapper<Object>> Objects::find(
    const std::string &name, const ObjectManager &objectManager,
    bool recursive) {
  for (const auto &object : objectManager.getObjects()) {
    if (object->getName() == name) return *object;
    if (!recursive) continue;
    auto child = find(name, object->getChildren(), recursive);
    if (child) return child;
  }
  return std::nullopt;
}

std::optional<std::reference_wrapper<Object>> Objects::find(
    const std::string &name, const Object &object, bool recursive) {
  auto child = find(name, object.getChildren(), recursive);
  if (child) return child;
  return std::nullopt;
}

std::optional<std::reference_wrapper<Object>> Objects::find_if(
    std::function<bool(const Object &object)> function, bool recursive) {
  auto global = find_if(Uniti::Game::Core::getSceneManager().getGlobalScene(),
                        function, recursive);
  if (global) return global;
  auto current = find_if(Uniti::Game::Core::getSceneManager().getCurrentScene(),
                         function, recursive);
  if (current) return current;
  return std::nullopt;
}

std::optional<std::reference_wrapper<Object>> Objects::find_if(
    const Scene &scene, std::function<bool(const Object &)> function,
    bool recursive) {
  auto object = find_if(scene.getObjects(), function, recursive);
  if (object) return object;
  return std::nullopt;
}

std::optional<std::reference_wrapper<Object>> Objects::find_if(
    const ObjectManager &objectManager,
    std::function<bool(const Object &)> function, bool recursive) {
  for (const auto &object : objectManager.getObjects()) {
    if (function(*object)) return *object;
    if (!recursive) continue;
    auto child = find_if(object->getChildren(), function, recursive);
    if (child) return child;
  }
  return std::nullopt;
}

std::optional<std::reference_wrapper<Object>> Objects::find_if(
    const Object &object, std::function<bool(const Object &)> function,
    bool recursive) {
  auto child = find_if(object.getChildren(), function, recursive);
  if (child) return child;
  return std::nullopt;
}
}  // namespace Uniti::Game::Utils