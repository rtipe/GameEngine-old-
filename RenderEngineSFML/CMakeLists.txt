cmake_minimum_required(VERSION 3.13)

target_sources(project PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp"
)

target_include_directories(project PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Assets)
add_subdirectory(Box)
add_subdirectory(Event)
add_subdirectory(Printable)
add_subdirectory(Sound)
add_subdirectory(Time)
add_subdirectory(Utils)
add_subdirectory(Vector)
add_subdirectory(Color)