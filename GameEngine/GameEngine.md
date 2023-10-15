# Creating a Game Engine for the R-Type Project

## Introduction

Our R-Type game project was developed by creating a custom game engine, an essential part of game development. The term "Game Engine" refers to a set of software and technologies that power and control key aspects of a video game. Our game engine draws inspiration from concepts used in game engines like Unity, which is widely employed in the game industry.

## Components of a Game Engine

A game engine is made up of several essential components that work together to create the gaming experience. Here are the key components that make up our game engine for the R-Type project:

1. **Scene Management:** The game engine manages game scenes and levels, enabling loading and transitions between different in-game environments.

2. **Rendering Engine:** It's responsible for the graphical rendering of the game, including rendering all in-game elements, managing visual effects, and handling cameras.

3. **Physics Engine:** The physics engine simulates the laws of physics for in-game objects, allowing realistic movements, collisions, and responses to external forces.

4. **Resource Management:** It effectively manages game assets like 3D models, textures, sounds, and scripts, loading them as needed to minimize loading times. Information is stored in JSON files for flexible management.

5. **Input Management:** The engine handles user input, such as keyboard, mouse, gamepad, and touch screen input, to interact with the game.

6. **Scripts:** Scripts are used to define the behavior of in-game objects, allowing for the programming of logic, movements, events, and more. Scripts are also defined using JSON files for modular management.

7. **Event Management:** Events facilitate communication between different in-game objects, allowing for event detection and appropriate responses. Events are configured using JSON files.

8. **Camera Management:** The engine manages the in-game cameras, enabling different viewing angles and tracking mechanisms.

9. **Audio:** It supports audio management, including sound and music playback, as well as environmental sound effects.

10. **Networking:** A network game engine can handle multiplayer connectivity, enabling players to play online or cooperatively. Network information is managed using JSON files.

## Using the Game Engine

To use our game engine in the R-Type project, we developed classes and systems for each component of the engine. Game developers created scenes, objects, scripts, and resources to design the gaming experience. Essential information, such as object properties, scripts, and events, is stored in JSON files for easy and flexible management.

Interaction with the engine is done using scripts and events. Scripts define the behavior of in-game objects, while events facilitate communication between objects. When creating a new level or feature, developers use the engine to load resources, manage inputs, and control in-game objects.

## The `Core` Class of the Game Engine

The `Core` class is a central component of our game engine. It provides essential features for starting and managing the engine. It can read JSON files to configure and initialize game elements.

- **`start()`:** Initializes and starts the game engine.

- **`getProjectInfo()`:** Retrieves project information from a JSON file.

- **`getSceneManager()`:** Obtains the scene manager configured through a JSON file.

- **`getScriptFactory()`:** Gets the script factory from JSON files.

- **`getWindow()`:** Retrieves the game's rendering window.

- **`getSound()`:** Fetches the sound manager, with information stored in a JSON file.

- **`getNetwork()`:** Retrieves the network manager configured via a JSON file.

- **`initProject(const std::string &projectPath)`:** Initializes a project by specifying the project's path, allowing JSON files to be loaded for configuration.

The `Core` class is responsible for managing the rendering window, scenes, scripts, resources, and network, ensuring smooth operation of the game.

## Conclusion

Our custom game engine is at the heart of the R-Type project, powering and controlling the entire gaming experience. Inspired by renowned game engines like Unity, it allowed us to create a feature-rich and content-packed game. This project provided an opportunity to apply our programming, game design, and project management skills while delivering an exciting gaming experience.
