//
// Created by youba on 05/10/2023.
//

#pragma once


#include <json/value.h>
#include "Scene.hpp"
#include "Transform.hpp"
#include "ObjectManager.hpp"
#include "ScriptManager.hpp"
#include "Movement.hpp"
#include "Collision.hpp"
#include "IPrintable.hpp"

namespace Uniti::Game {
    class Object {
    public:
        Object(const Object &object);
        Object(const Json::Value &value, Scene &scene);
        Object(const std::string &name, Scene &scene);
        void update();
        void setName(const std::string &name);
        const std::string &getName() const;
        void setEnable(bool value);
        bool isEnabled() const;
        const Transform &getTransform() const;
        Transform &getTransform();
        const ObjectManager &getChildren() const;
        ObjectManager &getChildren();
        const Scene &getScene() const;
        Scene &getScene();
        const ScriptManager &getScriptManager() const;
        ScriptManager &getScriptManager();
        const Movement &getMovement() const;
        Movement &getMovement();
        const Collision &getCollision() const;
        Collision &getCollision();
        const std::string &getLayer() const;
        void setLayer(const std::string &layer);
        const Render::IPrintable &getPrintable() const;
        Render::IPrintable &getPrintable();
        void setPrintable(Json::Value &value);
    private:
        Scene &_scene;
        Movement _movement;
        ScriptManager _scriptManager;
        Collision _collision;
        Transform _transform;
        std::unique_ptr<Render::IPrintable> _printable = nullptr;
        std::string _layer;
        ObjectManager _children;
        std::string _name;
        std::mutex _mutex;
    };
}
