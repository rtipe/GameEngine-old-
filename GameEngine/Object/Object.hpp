//
// Created by youba on 05/10/2023.
//

#pragma once

#include <json/value.h>
#include "Transform.hpp"
#include "ScriptManager.hpp"
#include "Movement.hpp"
#include "Collision.hpp"
#include "IPrintable.hpp"

namespace Uniti::Game {
    class Object;
    class Scene;
    class ObjectManager {
    public:
        ObjectManager(const Json::Value &value, Scene &scene);
        ObjectManager(const std::vector<std::unique_ptr<Object>> &objects);
        void add(std::unique_ptr<Object> object);
        void remove(const std::string &name);
        const std::vector<std::unique_ptr<Object>> &getObjects() const;
        std::vector<std::unique_ptr<Object>> &getObjects();
        void update();
        void emitEvent(const std::string &name, const Json::Value &value);
    private:
        std::vector<std::unique_ptr<Object>> _objects;
        std::vector<std::unique_ptr<Object>> _inObjects;
        std::vector<std::string> _outObjects;
        std::mutex _mutex;
    };
    class Object {
    public:
        Object(Object &object);
        Object(const Json::Value &value, Scene &scene);
        Object(const std::string &name, Scene &scene);
        void update();
        void setName(const std::string &name);
        const std::string &getName() const;
        std::string &getName();
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
        bool hasPrintable() const;
        const Render::IPrintable &getPrintable() const;
        Render::IPrintable &getPrintable();
        void setPrintable(const Json::Value &value);
        const Json::Value &getData() const;
    private:
        Json::Value _data;
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
        bool _isEnable = true;
    };
}
