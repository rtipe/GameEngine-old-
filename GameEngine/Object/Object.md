## Class Object

### Constructors

- **`Object(Object &object);`**
    - Description: Copy constructor taking an existing object and creating a new object by copying its properties.

- **`Object(const Json::Value &value, Scene &scene);`**
    - Description: Constructor taking a JSON value and a scene as parameters, creating a new object based on these data.

- **`Object(const std::string &name, Scene &scene);`**
    - Description: Constructor taking a name and a scene as parameters, creating a new object with the given name in the specified scene.

### Public Methods

- **`void update();`**
    - Description: Updates the object. This method is responsible for updating the object's state.

- **`void setName(const std::string &name);`**
    - Description: Modifies the object's name with the specified string.

- **`const std::string &getName() const;`**
    - Description: Retrieves the object's name as a constant reference to a string.

- **`std::string &getName();`**
    - Description: Retrieves the object's name as a reference to a string, allowing modification.

- **`void setEnable(bool value);`**
    - Description: Activates or deactivates the object based on the given boolean value.

- **`bool isEnabled() const;`**
    - Description: Checks if the object is enabled or not, returning a boolean corresponding to the activation state.

- **`const Transform &getTransform() const;`**
    - Description: Retrieves the object's transformation as a constant reference to a Transform object.

- **`Transform &getTransform();`**
    - Description: Retrieves the object's transformation as a reference to a Transform object, allowing modification.

- **`const ObjectManager &getChildren() const;`**
    - Description: Retrieves the object's child object manager as a constant reference to an ObjectManager object.

- **`ObjectManager &getChildren();`**
    - Description: Retrieves the object's child object manager as a reference to an ObjectManager object, allowing modification.

- **`const Scene &getScene() const;`**
    - Description: Retrieves the scene to which the object belongs as a constant reference to a Scene object.

- **`Scene &getScene();`**
    - Description: Retrieves the scene to which the object belongs as a reference to a Scene object, allowing modification.

- **`const ScriptManager &getScriptManager() const;`**
    - Description: Retrieves the object's script manager as a constant reference to a ScriptManager object.

- **`ScriptManager &getScriptManager();`**
    - Description: Retrieves the object's script manager as a reference to a ScriptManager object, allowing modification.

- **`const Movement &getMovement() const;`**
    - Description: Retrieves the object's movement data as a constant reference to a Movement object.

- **`Movement &getMovement();`**
    - Description: Retrieves the object's movement data as a reference to a Movement object, allowing modification.

- **`const Collision &getCollision() const;`**
    - Description: Retrieves the object's collision data as a constant reference to a Collision object.

- **`Collision &getCollision();`**
    - Description: Retrieves the object's collision data as a reference to a Collision object, allowing modification.

- **`const std::string &getLayer() const;`**
    - Description: Retrieves the name of the object's layer as a constant reference to a string.

- **`void setLayer(const std::string &layer);`**
    - Description: Modifies the name of the object's layer with the specified string.

- **`bool hasPrintable() const;`**
    - Description: Checks if the object has a printable element and returns a corresponding boolean value.

- **`const Render::IPrintable &getPrintable() const;`**
    - Description: Retrieves the object's printable element as a constant reference to a Render::IPrintable object.

- **`Render::IPrintable &getPrintable();`**
    - Description: Retrieves the object's printable element as a reference to a Render::IPrintable object, allowing modification.

- **`void setPrintable(const Json::Value &value);`**
    - Description: Modifies the object's printable element with the specified JSON value.

- **`const Json::Value &getData() const;`**
    - Description: Retrieves the object's data as a constant reference to a JSON value.

### Private Properties

- **`Json::Value _data;`**
    - Description: Stores the object's data in JSON format.

- **`Scene &_scene;`**
    - Description: Reference to the scene to which the object belongs.

- **`Movement _movement;`**
    - Description: Object of movement associated with the object.

- **`ScriptManager _scriptManager;`**
    - Description: Script manager associated with the object.

- **`Collision _collision;`**
    - Description: Object of collision associated with the object.

- **`Transform _transform;`**
    - Description: Object of transformation associated with the object.

- **`std::unique_ptr<Render::IPrintable> _printable = nullptr;`**
    - Description: Unique pointer to the object's printable element.

- **`std::string _layer;`**
    - Description: Name of the layer to which the object belongs.

- **`ObjectManager _children;`**
    - Description: Object manager for child objects associated with the object.

- **`std::string _name;`**
    - Description: Name of the object.

- **`std::mutex _mutex;`**
    - Description: Mutex for handling concurrency on the object.

- **`bool _isEnable = true;`**
    - Description: Indicates whether the object is enabled or not.
