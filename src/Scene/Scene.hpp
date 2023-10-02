//
// Created by youba on 25/09/2023.
//

#pragma once

#include <json/json.h>
#include "../AssetManager/AssetManager.hpp"

namespace UnitiGameEngine {
    class IObject;
    class Scene {
        public:
            Scene(const Json::Value &objects, const std::string &name = "");
            void addObject(std::unique_ptr<IObject> object);
            bool removeObject(std::size_t id);
            void update();
            const AssetManager &getAssetManager() const;
            AssetManager &getAssetManager();
            const std::vector<std::unique_ptr<IObject>> &getObjects() const;
            std::vector<std::unique_ptr<IObject>> &getObjects();
            const IObject &get(const std::string &name) const;
            IObject &get(const std::string &name);
            const std::string &getName() const;
        private:
            std::string _name;
            std::vector<std::unique_ptr<IObject>> _objects;
            AssetManager _assetManager;
    };
}