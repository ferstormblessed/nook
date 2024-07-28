#include "core/Coordinator.h"
#include <spdlog/spdlog.h>
#include "Systems/Physics/PhysicsSystem.h"
#include "components/Gravity.h"
#include "components/RigidBody.h"
#include "components/Transform.h"
#include "SFML/Graphics.hpp"
#include "components/Render.h"

#define WIDTH 1920u
#define HEIGHT 1080u
#define FRAMES 30

int main()
{
    spdlog::info("ENTRY POINT: STARTING GAME");
    auto coordinator = std::make_shared<NOOK::Coordinator>();
    coordinator->init();

    // TODO: make function that reads directory components and extracts the name of each file and registers the component
    // Register Components
    coordinator->registerComponent<NOOK::Gravity>();
    coordinator->registerComponent<NOOK::RigidBody>();
    coordinator->registerComponent<NOOK::Transform>();
    coordinator->registerComponent<NOOK::Render>();

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "nook");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
