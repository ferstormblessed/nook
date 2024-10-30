cmake_minimum_required(VERSION 3.16)
project(NOOK LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # Output directory for the library

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
        GIT_TAG             v3.0.0)
FetchContent_MakeAvailable(box2d)

add_library(NOOK STATIC
        include/NOOK/core/Types.h
        include/NOOK/components/Transform.h
        include/NOOK/core/EntityManager.h
        include/NOOK/core/ComponentArray.h
        include/NOOK/core/ComponentManager.h
        include/NOOK/core/System.h
        include/NOOK/core/SystemManager.h
        include/NOOK/core/Coordinator.h
        include/NOOK/components/RigidBody.h
        src/Systems/Physics/PhysicsSystem.cpp
        include/NOOK/Systems/Physics/PhysicsSystem.h
        include/NOOK/components/Sprite.h
        src/Systems/Render/RenderSpriteSystem.cpp
        include/NOOK/Systems/Render/RenderSpriteSystem.h
        include/NOOK/Utils/Register.h
        include/NOOK/Utils/Register.h
        include/NOOK/components/Shape.h
        include/NOOK/components/CircleShape.h
        src/Systems/Render/RenderShapeSystem.cpp
        include/NOOK/Systems/Render/RenderShapeSystem.h
        include/NOOK/components/RectangleShape.h
        src/Systems/Render/RenderTextSystem.cpp
        include/NOOK/Systems/Render/RenderTextSystem.h
        include/NOOK/components/Text.h
        include/NOOK/Utils/utils.h
        src/Utils/utils.cpp
        src/core/ResourceManager.cpp
        include/NOOK/core/ResourceManager.h
        include/NOOK/Utils/Config.h
        src/Systems/Movement/MovementSystem.cpp
        include/NOOK/Systems/Movement/MovementSystem.h
        include/NOOK/components/PlayerMove.h
        include/NOOK/components/PhysicsPolygon.h
        include/NOOK/components/PhysicsCircle.h
        include/NOOK/Systems/GameLogic/GameLogicSystem.h
        src/Systems/GameLogic/GameLogicSystem.cpp
        include/NOOK/components/Logic.h
        include/NOOK/components/Jump.h
        include/NOOK/Systems/Movement/JumpSystem.h
        src/Systems/Movement/JumpSystem.cpp
        include/NOOK/components/Pause.h
        include/NOOK/Systems/GameLogic/PauseSystem.h
        src/Systems/GameLogic/PauseSystem.cpp
        include/NOOK/components/GameOver.h
        include/NOOK/Systems/GameLogic/GameOverSystem.h
        include/NOOK/Systems/GameLogic/GameOverSystem.h
        src/Systems/GameLogic/GameOverSystem.cpp
        include/NOOK/components/IntVariableDebug.h
        include/NOOK/components/Debug.h
        include/NOOK/Systems/Debug/DebugSystem.h
        src/Systems/Debug/DebugSystem.cpp
        include/NOOK/components/BoolVariableDebug.h
        include/NOOK/components/FloatVariableDebug.h
        include/NOOK/GUI/Screens.h
        src/GUI/Screens.cpp
)

# Include SFML headers
include_directories(${SFML_INCLUDE_DIR})
# Include Imgui-SFML headers
include_directories(${imgui-sfml_SOURCE_DIR})
# Include Box2d headers
include_directories(${box2d_SOURCE_DIR}/include)

# Specify the include directories for the NOOK library
target_include_directories(NOOK
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>    # For users building the library
        $<INSTALL_INTERFACE:include>                        # For users using the installed library
        $<BUILD_INTERFACE:${SFML_SOURCE_DIR}/include>       # Incluye SFML para la construcción
        $<BUILD_INTERFACE:${imgui-sfml_SOURCE_DIR}>         # Incluye ImGui-SFML
        $<BUILD_INTERFACE:${box2d_SOURCE_DIR}>         # Incluye ImGui-SFML
)

target_link_libraries(NOOK PRIVATE sfml-graphics sfml-audio ImGui-SFML::ImGui-SFML box2d)
target_compile_features(NOOK PRIVATE cxx_std_17)

# Create an executable target
add_executable(main main.cpp)
# Link the NOOK library to the executable
target_link_libraries(main PRIVATE NOOK)

if(WIN32)
    add_custom_command(
            TARGET main
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
            VERBATIM)
endif()

install(TARGETS NOOK DESTINATION lib)  # Install command for the library
install(TARGETS main DESTINATION bin)   # Install command for the executable

# Install headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/NOOK/
        DESTINATION include/NOOK
        FILES_MATCHING PATTERN "*.h"
)
