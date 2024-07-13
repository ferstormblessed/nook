cmake_minimum_required(VERSION 3.16)
project(NOOK LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(ImGui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG v1.90.9-docking)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)

set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(ImGui-SFML
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(ImGui-SFML)

option(BOX2D_BUILD_UNIT_TESTS OFF)
FetchContent_Declare(box2d
        GIT_REPOSITORY      https://github.com/erincatto/Box2D.git
        GIT_TAG             v2.4.1)
FetchContent_MakeAvailable(box2d)

add_executable(main src/main.cpp
        src/utilities.h
        src/utilities.cpp
        src/gui.h
        src/gui.cpp
        src/NookManager.cpp
        src/NookManager.h)
target_link_libraries(main PRIVATE sfml-graphics ImGui-SFML::ImGui-SFML box2d)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()

install(TARGETS main)
