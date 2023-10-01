cmake_minimum_required(VERSION 3.25)
project(UnitiGameEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(jsoncpp CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(UnitiGameEngine
        test.cpp src/UnitiGame.cpp src/UnitiGame.hpp src/ProjectInfo.hpp src/ProjectInfo.cpp src/Object/IObject.hpp src/Object/Transform/Transform.hpp src/Object/Transform/Position.hpp src/Object/Transform/Scale.hpp src/Object/Transform/Rotation.hpp src/Scene/Scene.cpp src/Scene/Scene.hpp src/Scene/SceneManager.cpp src/Scene/SceneManager.hpp src/Scene/ScenePath.hpp src/AssetManager/AssetManager.cpp src/AssetManager/AssetManager.hpp src/Script/IScript.hpp src/Script/AScript.hpp src/Script/ScriptManager.cpp src/Script/ScriptManager.hpp
        src/Displayer/Displayer.hpp
        src/Displayer/Displayer.cpp
        src/Object/EmptyObject/EmptyObject.hpp
        src/Object/EmptyObject/EmptyObject.cpp
        src/Object/SpriteObject/SpriteObject.hpp
        src/Object/SpriteObject/SpriteObject.cpp
        src/Object/TextObject/TextObject.hpp
        src/Object/TextObject/TextObject.cpp
        src/Script/ScriptFactory.hpp
        src/Script/ScriptFactory.hpp
        src/Script/ScriptFactory.cpp src/Event/Input.hpp src/Event/Input.cpp scripts/VasselMovement.cpp scripts/VasselMovement.hpp scripts/ForwardParallax.cpp scripts/ForwardParallax.hpp)

target_link_libraries(UnitiGameEngine PRIVATE sfml-system sfml-network sfml-graphics sfml-window JsonCpp::JsonCpp)
