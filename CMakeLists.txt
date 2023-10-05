cmake_minimum_required(VERSION 3.15)

project(UnitiGameEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(JSONCpp
        GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
        GIT_TAG 1.9.5)
FetchContent_MakeAvailable(JSONCpp)

add_library(UnitiGameEngine STATIC
        src/UnitiGame.cpp src/UnitiGame.hpp src/ProjectInfo.hpp src/ProjectInfo.cpp src/Object/IObject.hpp src/Object/Transform/Transform.hpp src/Object/Transform/Position.hpp src/Object/Transform/Scale.hpp src/Object/Transform/Rotation.hpp src/Scene/Scene.cpp src/Scene/Scene.hpp src/Scene/SceneManager.cpp src/Scene/SceneManager.hpp src/Scene/ScenePath.hpp src/AssetManager/AssetManager.cpp src/AssetManager/AssetManager.hpp src/Script/IScript.hpp src/Script/AScript.hpp src/Script/ScriptManager.cpp src/Script/ScriptManager.hpp
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
        src/Script/ScriptFactory.cpp src/Event/Input.hpp src/Event/Input.cpp)

target_link_libraries(UnitiGameEngine sfml-graphics sfml-audio sfml-window sfml-system jsoncpp_lib)
target_compile_features(UnitiGameEngine PUBLIC cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET UnitiGameEngine
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:UnitiGameEngine>
            VERBATIM)
endif()

if(WIN32)
    add_custom_command(
            TARGET UnitiGameEngine
            COMMENT "Copy SFML DLLs"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86> $<TARGET_FILE_DIR:UnitiGameEngine>
            VERBATIM)
endif()

install(TARGETS UnitiGameEngine)