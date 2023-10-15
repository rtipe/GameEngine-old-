# Scene and SceneManager Classes - README

## Introduction

This README provides a comprehensive overview of the `Scene` and `SceneManager` classes within the Uniti game engine. These classes are vital for managing scenes, game objects, and facilitating scene transitions.

## Scene Class

### Constructors

- **`Scene(const Json::Value &scene, const std::string &name = "")`**: The `Scene` class constructor is responsible for creating a new scene. It takes a JSON configuration (`scene`) for the scene and an optional name. This constructor initializes the scene with the provided configuration and an optional name.

### Public Methods


- **`void update()`**: This method is used to update the state of the scene. It is called to advance the scene's logic and should be invoked within the game loop.

- **`const ObjectManager &getObjects() const`**: Returns a constant reference to the `ObjectManager` associated with the scene, allowing access to game objects within the scene without modification.

- **`ObjectManager &getObjects()`**: Returns a reference to the `ObjectManager`, enabling modifications and interaction with game objects within the scene.

- **`const AssetManager &getAssetManager() const`**: Provides a constant reference to the `AssetManager` for managing assets within the scene. This allows access to assets without the ability to modify them.

- **`AssetManager &getAssetManager()`**: Returns a reference to the `AssetManager`, permitting asset management and modifications.

- **`const std::string &getName() const`**: Retrieves the name of the scene, providing a way to identify and distinguish scenes.


## SceneManager Class

### Public Methods

- **`getCurrentScene()`**: Provides a reference to the current active scene, enabling interaction and modifications to the scene's properties.

- **`getGlobalScene()`**: Offers a reference to the global scene, typically serving as a static background for the game.

- **`getAllScenes()`**: Returns a list of available scenes as `ScenePath` objects, enabling scene selection.

- **`getScenePath(const std::string &name)`**: Allows retrieval of a scene's path (`ScenePath`) by specifying its name, facilitating scene location.

- **`addScenePath(ScenePath &scenePath)`**: Adds a new scene path to the list of available scenes, expanding scene selection.

- **`changeScene(const std.string &name)`**: Initiates a scene change by specifying the name of the target scene. Returns `true` if the scene change was successful.

- **`update()`**: Updates the current scene and should be called within the game loop to ensure smooth scene transitions.

- **`init()`**: Initializes the `SceneManager`, preparing it for use within the game during startup.

- **`getSceneValue(const ScenePath &scenePath)`**: Retrieves the JSON configuration for a specific scene identified by its `ScenePath`.

## Conclusion

The `Scene` and `SceneManager` classes are integral components of the Uniti game engine, allowing for efficient scene management and dynamic scene transitions. Developers can use these classes to create, modify, and transition between scenes in their games.

Please refer to the specific class documentation for more detailed information on constructors, methods, and properties.

