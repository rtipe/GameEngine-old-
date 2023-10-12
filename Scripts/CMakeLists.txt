cmake_minimum_required(VERSION 3.13)

target_sources(project PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/MouseMovement.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Animation.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/NetworkBase.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/InputField.cpp"
)

target_include_directories(project PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")