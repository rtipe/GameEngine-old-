//
// Created by youba on 05/10/2023.
//

#pragma once


#include <json/value.h>
#include "AssetManager.hpp"
#include "ObjectManager.hpp"

namespace Uniti::Game {
    class Scene {
    public:
        Scene(const Json::Value &scene, const std::string &name = "");
        void update();
        const ObjectManager &getObjects() const;
        ObjectManager &getObjects();
        const AssetManager &getAssetManager() const;
        AssetManager &getAssetManager();
        const std::string &getName() const;
    private:
        std::string _name;
        AssetManager _assetManager;
        ObjectManager _objectManager;
    };
}
