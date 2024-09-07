#include "Register.h"
#include "core/Coordinator.h"
#include <spdlog/spdlog.h>
#include "SFML/Graphics.hpp"
#include "Utils/utils.h"
#include "core/ResourceManager.h"
#include "SFML/Audio.hpp"

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
    renderSpriteSystem->init("/home/stormblessed/nook/src/sprites");
    // Physics System
    auto physicsSystem = NOOK::registerPhysicsSystem();
    physicsSystem->init();
    // ------------ REGISTER SYSTEMS ------------

//    spdlog::info("Audio available");
//    sf::SoundBuffer soundBuffer;
//    if (!soundBuffer.loadFromFile(config.ASSETS_PATH+config.AUDIO_DIRECTORY+"/ahem_x.wav")) {
//        spdlog::error("Failed to load sound:");
//        return 1;
//    }
//    sf::Sound sound;
//    sound.setBuffer(soundBuffer);
//    sound.play();


//    sf::SoundBuffer sound;
//    sound.loadFromFile("/home/stormblessed/nook/Assets/Audio/ahem_x.wav");
//    sf::Sound song;
//    song.setBuffer(sound);
//    song.play();

    // Entities

    // Paddles
//    NOOK::Entity l_paddle = gCoordinator.createEntity();
//    NOOK::Entity r_paddle = gCoordinator.createEntity();

    // circle
//    NOOK::Entity circle = gCoordinator.createEntity();
//    gCoordinator.addComponent(circle,NOOK::Shape{ .isCircle = true, .color = sf::Color::Red });
//    gCoordinator.addComponent(circle,NOOK::CircleShape{ .radius = 100, .numSides = 3 });
//
//    // rectangle
//    NOOK::Entity rectangle = gCoordinator.createEntity();
//    gCoordinator.addComponent(rectangle,NOOK::Shape{ .isRectangle = true, .color = sf::Color::Blue });
//    gCoordinator.addComponent(rectangle,NOOK::RectangleShape{ .height = 100, .width = 300 });

    // mosca
//    NOOK::Entity mosca = gCoordinator.createEntity();
//    gCoordinator.addComponent(mosca, NOOK::Sprite{ .spriteName = "mosca" });

    // Text
    NOOK::Entity text = gCoordinator.createEntity();
    gCoordinator.addComponent(text, NOOK::Text{
            .font = "vinque.rg-regular",
            .text = "Hello there!",
            .size = 500,
            .color = sf::Color::White,
            .isUnderlined = true
    });

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
        renderShapeSystem->update(&window);
        renderTextSystem->update(&window);
        renderSpriteSystem->update(&window);

        window.display();
    }

    return 0;
}
