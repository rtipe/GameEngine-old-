# Class Scene

The `Scene` class is part of the Uniti game engine and is designed to manage game scenes. It allows developers to create and manipulate scenes within the game, providing control over game objects and assets. This documentation outlines the class's constructors and essential methods, describing how to use the `Scene` class effectively.

## Constructors

- **`Scene(const Json::Value &scene, const std::string &name = "")`**: Constructor for creating a `Scene` object. It takes a JSON configuration for the scene and an optional name. This constructor initializes the scene with the provided configuration and an optional name.

## Public Methods

- **`void update()`**: This method is used to update the state of the scene. It is called to advance the scene's logic and should be invoked within the game loop.

- **`const ObjectManager &getObjects() const`**: Returns a constant reference to the `ObjectManager` associated with the scene, allowing access to game objects within the scene without modification.

- **`ObjectManager &getObjects()`**: Returns a reference to the `ObjectManager`, enabling modifications and interaction with game objects within the scene.

- **`const AssetManager &getAssetManager() const`**: Provides a constant reference to the `AssetManager` for managing assets within the scene. This allows access to assets without the ability to modify them.

- **`AssetManager &getAssetManager()`**: Returns a reference to the `AssetManager`, permitting asset management and modifications.

- **`const std::string &getName() const`**: Retrieves the name of the scene, providing a way to identify and distinguish scenes.

## Private Properties

- **`std::string _name`**: A private property that stores the name of the scene.

- **`AssetManager _assetManager`**: An instance of the `AssetManager` class responsible for managing assets within the scene.

- **`ObjectManager _objectManager`**: An instance of the `ObjectManager` class that handles game objects within the scene.

---

*This documentation outlines the usage of the `Scene` class, providing an overview of its constructors, methods, and properties. Developers can utilize this class to create, manage, and control scenes in the Uniti game engine.*
