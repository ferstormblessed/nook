cmake_minimum_required(VERSION 3.16)
project(NOOK LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # Output directory for the library

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

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
        src/Systems/Physics/PhysicsSystem.cpp
        src/Systems/Render/RenderSpriteSystem.cpp
        src/Systems/Render/RenderShapeSystem.cpp
        src/Systems/Render/RenderTextSystem.cpp
        src/Utils/utils.cpp
        src/core/ResourceManager.cpp
        src/Systems/Movement/MovementSystem.cpp
        src/Systems/GameLogic/GameLogicSystem.cpp
        src/Systems/Movement/JumpSystem.cpp
        src/Systems/GameLogic/PauseSystem.cpp
        src/Systems/GameLogic/GameOverSystem.cpp
        src/Systems/Debug/DebugSystem.cpp
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
add_executable(main main.cpp
        Games/Platformer.h
)
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