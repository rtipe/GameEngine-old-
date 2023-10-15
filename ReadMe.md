# R-Type Project - Project Report

![R-Type Logo](./assets/Doc/LogoRtype.png)

## Introduction

This document reports our third-year project at Epitech, where we embarked on the development of an R-Type game. In the scope of this project, we designed our own game engine and implemented a network to enable the game to be played online via a server that we created. This report provides an overview of the project, including objectives, development steps, challenges encountered, and achievements.

## Project Architecture

Our R-Type project is built on a well-defined software architecture, including the following components:

1. **Custom Game Engine:** We developed our own game engine to power the R-Type game. It manages graphics, physics, inputs, and resource management.

2. **R-Type Game:** The game itself is built on our custom game engine. It includes levels, enemies, players, and gameplay features.

3. **Multiplayer Network:** We set up a network to allow players to play online. It manages the synchronization of game data between clients and the server.

4. **Resource Management:** A resource management system has been implemented to efficiently load images, sounds, and other assets in the game.

## Game

For more details about the game, click below
[R-Type](game.md)

## Game Engine

For more details about the game engine, click below
[Game Engine](./GameEngine/GameEngine.md)

## Build

1. Create a build directory at the root:
    ```bash
    mkdir build
    cd build

2. Compile in this directory:
    ```bash
    cmake ..
    make

3. Go to the bin directory created by the compilation:
    ```bash
    cd bin

4. Execute the binary in the root of the repository:
    ```bash
    mv project ../../
    cd ../../
    ./project

## Conclusion

This third-year project at Epitech offered us the opportunity to develop a complete R-Type game, create our own game engine, and implement a network to make it playable online. This experience allowed us to put our programming, game design, and project management skills into practice. We are proud of the achievements of this project and the enriching experience it provided.

## Contributors

- abdelkader.mazouz@peitech.eu
- vincent.ballandi@epitech.eu
- younes1.bahri@epitech.eu
- swann.lagoute@epitech.eu
- simon.vermeulen@epitech.eu
