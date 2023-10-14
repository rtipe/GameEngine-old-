cmake_minimum_required(VERSION 3.22)
project(project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)
include(CPack)

set(CPACK_PACKAGE_NAME "rtype")

message(STATUS "Fetching SFML")

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

message(STATUS "Fetching JSONCPP")

FetchContent_Declare(JSONCpp
        GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
        GIT_TAG 1.9.5)
FetchContent_MakeAvailable(JSONCpp)

FetchContent_Declare(
        Boost
        URL "https://github.com/boostorg/boost/releases/download/boost-1.83.0/boost-1.83.0.tar.xz"
        DOWNLOAD_EXTRACT_TIMESTAMP ON
)

set(BOOST_RUNTIME_LINK static)
set(BOOST_INCLUDE_LIBRARIES
        asio
        assert
        align
        array
        bind
        coroutine
        config
        context
        core
        chrono
        date_time
        exception
        function
        move
        system
        smart_ptr
        throw_exception
        type_traits
        lockfree
        utility
)
FetchContent_MakeAvailable(Boost)

find_package(Threads REQUIRED)


add_executable(project)
foreach(lib ${BOOST_INCLUDE_LIBRARIES})
    target_link_libraries(
            project
            PRIVATE
            Boost::${lib}
    )
endforeach()

target_link_libraries(project PRIVATE Threads::Threads)

target_link_libraries(project PRIVATE sfml-graphics sfml-window sfml-system sfml-audio jsoncpp_lib)

add_subdirectory(GameEngine)
add_subdirectory(RenderEngineSFML)
add_subdirectory(src)
add_subdirectory(Scripts)

if(WIN32)
    add_custom_command(
            TARGET project
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:project>
            VERBATIM)
endif()

if(WIN32)
    add_custom_command(
            TARGET project
            COMMENT "Copy SFML DLLs"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86> $<TARGET_FILE_DIR:project>
            VERBATIM)
endif()