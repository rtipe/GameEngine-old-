## Class Script : public Uniti::Game::AScript

The `Script` class, inheriting from `Uniti::Game::AScript`, represents a script attached to a game object. Scripts are used to add custom behaviors and functionality to objects in a game or graphical application. This class defines essential methods for script execution, allowing developers to control the behavior of game objects dynamically.

### Constructors

- **`explicit Script(Uniti::Game::Object &gameObject)`**: Constructor initializing the `Script` object with a reference to the associated `Uniti::Game::Object` instance.

### Public Methods

- **`void start() override`**: Overrides the `start` method from `Uniti::Game::AScript`. This method is called when the script starts its execution.

- **`void update() override`**: Overrides the `update` method from `Uniti::Game::AScript`. This method is called periodically to update the script logic during runtime.

- **`void awake(const Json::Value &value) override`**: Overrides the `awake` method from `Uniti::Game::AScript`. This method is called when the script is initialized, providing a JSON value for configuration.

### Private Properties

- **`Uniti::Game::Object &_gameObject`**: Reference to the associated game object, enabling interaction and modification of the object's properties.

---

*This documentation outlines the methods and properties of the `Script` class, serving as a guide for developers implementing custom script behaviors within the Uniti game engine.*
