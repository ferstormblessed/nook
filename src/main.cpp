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
sf::RenderWindow window;

int main()
{
    spdlog::info("ENTRY POINT: STARTING GAME");
    // Initialize coordinator
    gCoordinator.init();
    spdlog::info("Finish Coordinator initialization");

    // TODO: make function that reads directory components and extracts the name of each file and registers the component
    // Register Components
    gCoordinator.registerComponent<NOOK::Gravity>();
    gCoordinator.registerComponent<NOOK::RigidBody>();
    gCoordinator.registerComponent<NOOK::Transform>();
    gCoordinator.registerComponent<NOOK::Render>();

    //Render System initialization
    auto renderSystem = gCoordinator.registerSystem<NOOK::RenderSystem>();
    {
        NOOK::Signature signature;
        signature.set(gCoordinator.getComponentType<NOOK::Render>());
        gCoordinator.setSystemSignature<NOOK::RenderSystem>(signature);
    }
    renderSystem->init();

    // Entities
    std::vector<NOOK::Entity> entities(3);

    for (auto& entity : entities) {
        entity = gCoordinator.createEntity();
        gCoordinator.addComponent(entity,
                                  NOOK::Render{
                                          .image = "images/texture.jpg",
                                  });
    }

    // Game loop
    // TODO: try to abstract this to a separate function
    window.create(sf::VideoMode(800, 600), "nook");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        //renderSystem->update();
        window.display();
    }

    return 0;
}
