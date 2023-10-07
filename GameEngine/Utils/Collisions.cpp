//
// Created by youba on 07/10/2023.
//

#include "Collisions.hpp"
#include "Uniti.hpp"

namespace Uniti::Game::Utils {
    std::optional<std::reference_wrapper<Object>> Collisions::isCollided(const Render::Vector2f &position) {
        for (const auto &object : Uniti::Game::Core::getSceneManager().getGlobalScene().getObjects().getObjects()) {
            if (object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        for (const auto &object : Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().getObjects()) {
            if (object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>> Collisions::isCollided(const Render::Vector3f &position) {
        for (const auto &object : Uniti::Game::Core::getSceneManager().getGlobalScene().getObjects().getObjects()) {
            if (object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside({position.getX(), position.getY()}))
                return *object;
        }
        for (const auto &object : Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().getObjects()) {
            if (object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside({position.getX(), position.getY()}))
                return *object;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>> Collisions::isCollided(const Render::Box &position) {
        for (const auto &object : Uniti::Game::Core::getSceneManager().getGlobalScene().getObjects().getObjects()) {
            if (object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        for (const auto &object : Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().getObjects()) {
            if (object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>> Collisions::isCollided(const Object &position) {
        for (const auto &object : Uniti::Game::Core::getSceneManager().getGlobalScene().getObjects().getObjects()) {
            if (object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        for (const auto &object : Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().getObjects()) {
            if (object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>> Collisions::isOverlapped(const Render::Vector2f &position) {
        for (const auto &object : Uniti::Game::Core::getSceneManager().getGlobalScene().getObjects().getObjects()) {
            if (!object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        for (const auto &object : Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().getObjects()) {
            if (!object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>> Collisions::isOverlapped(const Render::Vector3f &position) {
        for (const auto &object : Uniti::Game::Core::getSceneManager().getGlobalScene().getObjects().getObjects()) {
            if (!object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside({position.getX(), position.getY()}))
                return *object;
        }
        for (const auto &object : Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().getObjects()) {
            if (!object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside({position.getX(), position.getY()}))
                return *object;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>> Collisions::isOverlapped(const Render::Box &position) {
        for (const auto &object : Uniti::Game::Core::getSceneManager().getGlobalScene().getObjects().getObjects()) {
            if (!object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        for (const auto &object : Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().getObjects()) {
            if (!object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>> Collisions::isOverlapped(const Object &position) {
        for (const auto &object : Uniti::Game::Core::getSceneManager().getGlobalScene().getObjects().getObjects()) {
            if (!object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        for (const auto &object : Uniti::Game::Core::getSceneManager().getCurrentScene().getObjects().getObjects()) {
            if (!object->getCollision().isOverlap())
                continue;
            if (object->getCollision().isInside(position))
                return *object;
        }
        return std::nullopt;
    }
}