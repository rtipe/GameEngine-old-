cmake_minimum_required(VERSION 3.13)

target_sources(project PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Objects.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Script.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Collisions.cpp"
)

target_include_directories(project PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")