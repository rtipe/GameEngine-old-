## Abstract Class AScript : public IScript

The `AScript` class, derived from the `IScript` interface, serves as an abstract base class for implementing custom scripts within the Uniti game engine. It provides access to the game object, event handling, and clock functionalities, enabling developers to create dynamic and interactive behaviors for game objects.

### Constructors

- **`AScript(Object &object)`**: Constructor initializing the `AScript` object with a reference to the associated `Object` instance. This constructor is protected, ensuring that `AScript` instances can only be created through a factory pattern.

### Protected Methods

- **`const Object &getGameObject() const override`**: Overrides the `getGameObject` method from `IScript` and returns a constant reference to the associated game object.

- **`Object &getGameObject() override`**: Overrides the `getGameObject` method from `IScript` and returns a reference to the associated game object, allowing modifications.

- **`const Event &getEvent() const override`**: Overrides the `getEvent` method from `IScript` and returns a constant reference to the event object, enabling event handling within the script.

- **`Event &getEvent() override`**: Overrides the `getEvent` method from `IScript` and returns a reference to the event object, allowing modifications and event emission within the script.

- **`const Render::Clock &getClock() const override`**: Overrides the `getClock` method from `IScript` and returns a constant reference to the clock object, providing access to time-related functionalities.

- **`Render::Clock &getClock() override`**: Overrides the `getClock` method from `IScript` and returns a reference to the clock object, allowing modifications and time-related calculations within the script.

### Private Properties

- **`Object &_gameObject`**: Reference to the associated game object, enabling interaction and modification of the object's properties within the script.

- **`Event _event`**: Event object for handling events within the script.

- **`Render::Clock _clock`**: Clock object for tracking time, used for time-related calculations within the script.

---

*This documentation outlines the methods and properties of the `AScript` class, emphasizing its usage in conjunction with a factory pattern. The factory pattern allows developers to create instances of `AScript` classes, ensuring proper initialization and encapsulation of script functionalities.*
