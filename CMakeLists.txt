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

FetchContent_Declare(spdlog
        GIT_REPOSITORY      https://github.com/gabime/spdlog
        GIT_TAG             v1.x)
FetchContent_MakeAvailable(spdlog)

add_executable(main src/main.cpp
        src/core/Types.h
        src/components/Transform.h
        src/core/EntityManager.h
        src/core/ComponentArray.h
        src/core/ComponentManager.h
        src/core/System.h
        src/core/SystemManager.h
        src/core/Coordinator.h
        src/components/RigidBody.h
        src/components/Gravity.h
        src/Systems/Physics/PhysicsSystem.cpp
        src/Systems/Physics/PhysicsSystem.h
        src/components/Sprite.h
        src/Systems/Render/RenderSystem.cpp
        src/Systems/Render/RenderSystem.h
        src/utils.h
        src/utils.h
        src/Input/Input.cpp
        src/Input/Input.h
        src/components/Shape.h
        src/components/CircleShape.h
        src/Systems/Render/RenderShapeSystem.cpp
        src/Systems/Render/RenderShapeSystem.h
        src/components/RectangleShape.h
)
target_link_libraries(main PRIVATE sfml-graphics ImGui-SFML::ImGui-SFML box2d spdlog)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()

install(TARGETS main)
