#include "Register.h"
#include "core/Coordinator.h"
#include <spdlog/spdlog.h>
#include "core/ResourceManager.h"
#include "SFML/Audio.hpp"
#include "Config.h"
#include "Utils/utils.h"
#include "Games/Pong.h"

NOOK::Coordinator gCoordinator;
NOOK::ResourceManager resourceManager;

int main() {
    spdlog::info("ENTRY POINT: STARTING GAME");
    // Initialize coordinator
    gCoordinator.init();

    // ------------ LOAD CONFIG ------------
    NOOK::Config config = NOOK::loadConfigFromFile("/home/stormblessed/nook/src/config.txt");
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
    // ------------ REGISTER SYSTEMS ------------

    // Pong
    NOOK::Pong(config);

    // Game loop
    // TODO: try to abstract this to a separate function
    sf::RenderWindow window;
    window.setFramerateLimit(config.FRAMES);
    sf::Clock clock;
    window.create(sf::VideoMode(config.WIDTH, config.HEIGHT), config.WINDOW_TITLE);

    while (window.isOpen()) {
        clock.restart();
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // TODO: could each system be on its own thread? Maybe not, because i need the physics transformations
        physicsSystem->update(clock.restart().asSeconds());
        movementSystem->update(&event);
        renderShapeSystem->update(&window);
        renderTextSystem->update(&window);
        renderSpriteSystem->update(&window);

        window.display();
    }

    return 0;
}
