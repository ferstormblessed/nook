#include "utils.h"
#include "core/Coordinator.h"
#include <spdlog/spdlog.h>
#include "Systems/Physics/PhysicsSystem.h"
#include "components/Gravity.h"
#include "components/RigidBody.h"
#include "components/Transform.h"
#include "SFML/Graphics.hpp"
#include "components/Render.h"
#include "Systems/Render/RenderSystem.h"

#define WIDTH 1920u
#define HEIGHT 1080u
#define FRAMES 30


NOOK::Coordinator gCoordinator;

int main()
{
    spdlog::info("ENTRY POINT: STARTING GAME");
    // Initialize coordinator
    gCoordinator.init();
    spdlog::info("Finish Coordinator initialization");

    // Register COMPONENTS
    registerComponents();

    // Render System initialization
    auto renderSystem = registerRenderSystem();
    renderSystem->init();

    // Physics System initialization
    auto physicsSystem = registerPhysicsSystem();
    physicsSystem->init();
//    auto physicsSystem = gCoordinator.registerSystem<NOOK::PhysicsSystem>();
//    {
//        NOOK::Signature signature;
//        signature.set(gCoordinator.getComponentType<NOOK::Transform>());
//        signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
//        signature.set(gCoordinator.getComponentType<NOOK::Gravity>());
//        gCoordinator.setSystemSignature<NOOK::PhysicsSystem>(signature);
//    }

    // Entities
    std::vector<NOOK::Entity> entities(1);

    for (auto& entity : entities) {
        entity = gCoordinator.createEntity();
        gCoordinator.addComponent(entity,
                                  NOOK::Render{
                                          .image = "/home/stormblessed/nook/src/images/mosca.png",
                                  });
        gCoordinator.addComponent(entity,
                                  NOOK::Transform{
                                          .position = b2Vec2(float(WIDTH)/2, 0),
                                          .rotation = b2Vec3(0, 0, 0),
                                          .scale = b2Vec2(1, 0.5)
                                  });
        gCoordinator.addComponent(entity,
                                  NOOK::Gravity{
                                          .force = b2Vec2(0.0f, 10)
                                  });
        gCoordinator.addComponent(entity,
                                  NOOK::RigidBody{});
    }

    // Game loop
    // TODO: try to abstract this to a separate function
    sf::RenderWindow window;
    window.setFramerateLimit(FRAMES);
    sf::Clock clock;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "NOOK");

    // run the program as long as the window is open
    while (window.isOpen()) {
        clock.restart();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        physicsSystem->update(clock.restart().asSeconds());
        renderSystem->update(&window);
        window.display();
    }

    return 0;
}
