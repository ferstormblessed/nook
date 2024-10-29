#include "Utils/Register.h"
#include "core/Coordinator.h"
#include <spdlog/spdlog.h>
#include "core/ResourceManager.h"
#include "SFML/Audio.hpp"
#include "Config.h"
#include "Utils/utils.h"
#include "Games/Pong.h"
#include "Games/InfiniteRunner.h"
#include "imgui-SFML.h"

NOOK::Coordinator gCoordinator;
NOOK::ResourceManager resourceManager;
// TODO: fix config uses
NOOK::Config config;
NOOK::GAME_STATE gameState = NOOK::PLAY_STATE;

int main() {
    spdlog::info("ENTRY POINT: STARTING GAME");
    // Initialize coordinator
    gCoordinator.init();

    // ------------ WORLD BOX2D ------------
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = (b2Vec2){0.0f, 10.0f};
    b2WorldId worldId = b2CreateWorld(&worldDef);
    b2World_SetHitEventThreshold(worldId, 0.01f);
    // ------------ WORLD BOX2D ------------

    // ------------ LOAD CONFIG ------------
    config = NOOK::loadConfigFromFile("/home/stormblessed/nook/src/config.txt");
    // ------------ LOAD CONFIG ------------

    // ------------ RESOURCE MANAGER ------------
    resourceManager.m_assetsPath = config.ASSETS_PATH;
    resourceManager.m_fontsDirectory = config.FONTS_DIRECTORY;
    resourceManager.m_soundsDirectory = config.AUDIO_DIRECTORY;
    resourceManager.m_textureDirectory = config.SPRITES_DIRECTORY;
    resourceManager.init();
    // ------------ RESOURCE MANAGER ------------

    // Register COMPONENTS
    NOOK::registerComponents();

    // ------------ REGISTER SYSTEMS ------------
    // Render Shape System
    auto renderShapeSystem = NOOK::registerRenderShapeSystem();
    renderShapeSystem->init();
    // Render Text System
    auto renderTextSystem = NOOK::registerRenderTextSystem();
    renderTextSystem->init();
    // Render System system
    auto renderSpriteSystem = NOOK::registerRenderSpriteSystem();
    renderSpriteSystem->init();
    // Physics System
    auto physicsSystem = NOOK::registerPhysicsSystem();
    physicsSystem->init();
    // Movement System
    auto movementSystem = NOOK::registerMovementSystem();
    movementSystem->init();
    // Jump System
    auto jumpSystem = NOOK::registerJumpSystem();
    jumpSystem->init();
    // Game Logic System
    auto gameLogicSystem = NOOK::registerGameLogicSystem();
    gameLogicSystem->init();
    // Pause System
    auto pauseSystem = NOOK::registerPauseSystem();
    pauseSystem->init();
    // Game Over System
    auto gameOverSystem = NOOK::registerGameOverSystem();
    gameOverSystem->init();
    // Debug System
    auto debugSystem = NOOK::registerDebugSystem();
    debugSystem->init();
    // ------------ REGISTER SYSTEMS ------------

    // ----------------- GAMES ------------------
    // Pong
    Pong::Pong(config);
    // Infinite Runner
    // InfiniteRunner::InfiniteRunner(config);
    // ----------------- GAMES ------------------

    // ---------------- GAME LOOP ---------------
    // TODO: abstract this to a separate function

    sf::RenderWindow window;
    window.setFramerateLimit(config.FRAMES);
    sf::Clock clock;
    window.create(sf::VideoMode(config.WIDTH, config.HEIGHT), config.WINDOW_TITLE);
    if (!ImGui::SFML::Init(window)) return -1;

    // TODO: change awake implementation. Awake runs only in the first frame of the game
    // ----------------- AWAKE ------------------
    int iteration = 0;
    while (window.isOpen()) {
        if (iteration < 1) {
            physicsSystem->awake(worldId);
            iteration++;
        }
    // ----------------- AWAKE ------------------

        sf::Event event{};
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, clock.restart());

        window.clear();

        // TODO: could each system be on its own thread? Maybe not, because i need the physics transformations
        physicsSystem->update(worldId, gameState);
        movementSystem->update(&event, gameState);
        jumpSystem->update(&event, gameState);
        renderShapeSystem->update(&window);
        renderTextSystem->update(&window);
        renderSpriteSystem->update(&window);
        gameLogicSystem->update();
        pauseSystem->update(&event, gameState);
        gameOverSystem->update(gameState);
        debugSystem->update(&event);

        ImGui::SFML::Render(window);

        window.display();
    }
    ImGui::SFML::Shutdown();

    // ---------------- GAME LOOP ---------------
    return 0;
}