cmake_minimum_required(VERSION 3.13)

target_sources(project PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/MouseMovement.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Parallax.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ButtonNavigation.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Animation.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/NetworkBase.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/InputField.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/MissileHandler.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/DisplayHP.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Timer.cpp"
)

target_include_directories(project PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")