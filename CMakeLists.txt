cmake_minimum_required(VERSION 3.22)
project(project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

add_executable(project
        RenderEngine/Printable/IPrintable.hpp)

find_package(jsoncpp CONFIG REQUIRED)

target_link_libraries(project PRIVATE JsonCpp::JsonCpp)

add_subdirectory(GameEngine)
add_subdirectory(RenderEngine)
