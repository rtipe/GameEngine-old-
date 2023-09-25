//
// Created by youba on 25/09/2023.
//

#pragma once

#include <json/json.h>
#include "../Object/IObject.hpp"
#include "../UnitiGame.hpp"
#include "../AssetManager/AssetManager.hpp"

namespace UnitiGameEngine {
    class Scene {
        public:
            Scene(const Json::Value &objects, Uniti &game, const std::string &name = "");
            void addObject(IObject &object);
            bool removeObject(std::size_t id);
            bool moveObjectTo(std::size_t id, Scene &scene);
            void display();
            const Uniti &getGame() const;
            Uniti &getGame();
            const AssetManager &getAssetManager() const;
            AssetManager &getAssetManager();
            const std::vector<IObject> &getObjects() const;
            std::vector<IObject> &getObjects();
            const IObject &get() const;
            IObject &get();
            const std::string &getName() const;
        private:
            std::string _name;
            std::vector<IObject> _objects;
            Uniti &_game;
            AssetManager _assetManager;
    };
}