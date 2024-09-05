#include "Register.h"
#include "core/Coordinator.h"
#include <spdlog/spdlog.h>
#include "SFML/Graphics.hpp"

#define WIDTH 1920u
#define HEIGHT 1080u
#define FRAMES 30

NOOK::Coordinator gCoordinator;

int main()
{
    spdlog::info("ENTRY POINT: STARTING GAME");
    // Initialize coordinator
    gCoordinator.init();

    // Register COMPONENTS
    NOOK::registerComponents();

    // ------------ REGISTER SYSTEMS ------------
    // Render Shape System
    auto renderShapeSystem = NOOK::registerRenderShapeSystem();
    renderShapeSystem->init();
    // Render Text System
    auto renderTextSystem = NOOK::registerRenderTextSystem();
    renderTextSystem->init("/home/stormblessed/nook/src/fonts");
    // Render System system
    auto renderSpriteSystem = NOOK::registerRenderSpriteSystem();
    renderSpriteSystem->init("/home/stormblessed/nook/src/sprites");
    // Physics System
    auto physicsSystem = NOOK::registerPhysicsSystem();
    physicsSystem->init();
    // ------------ REGISTER SYSTEMS ------------

    // Entities

    // Paddles
//    NOOK::Entity l_paddle = gCoordinator.createEntity();
//    NOOK::Entity r_paddle = gCoordinator.createEntity();

//    // circle
//    NOOK::Entity circle = gCoordinator.createEntity();
//    gCoordinator.addComponent(circle,NOOK::Shape{ .isCircle = true, .color = sf::Color::Red });
//    gCoordinator.addComponent(circle,NOOK::CircleShape{ .radius = 100, .numSides = 3 });
//
//    // rectangle
//    NOOK::Entity rectangle = gCoordinator.createEntity();
//    gCoordinator.addComponent(rectangle,NOOK::Shape{ .isRectangle = true, .color = sf::Color::Blue });
//    gCoordinator.addComponent(rectangle,NOOK::RectangleShape{ .height = 100, .width = 300 });

    // mosca
    NOOK::Entity mosca = gCoordinator.createEntity();
    gCoordinator.addComponent(mosca, NOOK::Sprite{ .spriteName = "texture" });

    // Text
//    NOOK::Entity text = gCoordinator.createEntity();
//    gCoordinator.addComponent(text, NOOK::Text{
//            .font = "vinque.rg-regular",
//            .text = "Hello there!",
//            .size = 500,
//            .color = sf::Color::White,
//            .isUnderlined = true
//    });


    // Game loop
    // TODO: try to abstract this to a separate function
    sf::RenderWindow window;
    window.setFramerateLimit(FRAMES);
    sf::Clock clock;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "NOOK");

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
