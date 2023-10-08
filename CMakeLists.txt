cmake_minimum_required(VERSION 3.22)
project(project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

add_executable(project)

find_package(Threads REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

target_link_libraries(project PRIVATE sfml-graphics sfml-audio sfml-window sfml-system jsoncpp_lib Threads::Threads)

add_subdirectory(GameEngine)
add_subdirectory(RenderEngineSFML)
add_subdirectory(src)
add_subdirectory(Scripts)
