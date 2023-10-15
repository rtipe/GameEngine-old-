## Class Event

The `Event` class, within the `Uniti::Game` namespace, provides a mechanism for managing and triggering events in a game or graphical application. Events are represented by string names and can be associated with callback functions. This class allows the addition, removal, and emission of events, enabling a flexible and decoupled way to handle interactions and behaviors within the application.

### Public Methods

- **`std::size_t addEvent(const std::string &name, eventFunction function)`**: Adds a new event with the specified `name` and associates it with the provided `eventFunction`. Returns a unique identifier for the added event, allowing removal later if needed.

- **`void removeEvent(const std::string &name)`**: Removes all callbacks associated with the event specified by `name`. All functions registered under this event name will be removed.

- **`void removeEvent(const std::string &name, std::size_t id)`**: Removes a specific callback identified by the unique `id` from the event specified by `name`.

- **`void emitEvent(const std::string &name, const Json::Value &value)`**: Emits an event with the given `name` and passes the provided `Json::Value` parameter to all registered callbacks associated with the event. This triggers the execution of all registered functions for that event.

### Private Properties

- **`std::map<std::string, std::vector<eventFunction>> _events`**: A map where each event name is associated with a vector of `eventFunction` callbacks. Events are stored as keys, and each key maps to a vector of functions to be executed when the event is emitted.

- **`std::mutex _mutex`**: Mutex for handling concurrency and ensuring thread safety, allowing multiple threads to safely add, remove, and emit events.

---

*This documentation outlines the methods and properties of the `Event` class, providing developers with the ability to create a robust event system within the Uniti game engine.*
