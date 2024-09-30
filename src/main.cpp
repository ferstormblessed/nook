#include "Utils/Register.h"
#include "core/Coordinator.h"
#include <spdlog/spdlog.h>
#include "core/ResourceManager.h"
#include "SFML/Audio.hpp"
#include "Config.h"
#include "Utils/utils.h"
#include "Games/Pong.h"
#include "box2d/box2d.h"
#include "components/b2PolygonComponent.h"

NOOK::Coordinator gCoordinator;
NOOK::ResourceManager resourceManager;
// TODO: fix config uses
NOOK::Config config;

int main() {
    spdlog::info("ENTRY POINT: STARTING GAME");
    // Initialize coordinator
    gCoordinator.init();

    // ------------ WORLD BOX2D ------------
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = (b2Vec2){0.0f, 10.0f};
    b2WorldId worldId = b2CreateWorld(&worldDef);
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
    // Bounce Physics System
    auto bouncePhysicsSystem = NOOK::registerBouncePhysicsSystem();
    bouncePhysicsSystem->init();
    // ------------ REGISTER SYSTEMS ------------

    // Pong
    // NOOK::Pong(config);

    NOOK::Entity box = gCoordinator.createEntity();
    NOOK::RigidBody rb;
    rb.bodyType = b2_dynamicBody;
    rb.position = b2Vec2{config.WIDTH / 2.0f, config.HEIGHT / 2.0f};
    rb.shapeType = NOOK::b2Polygon;
    rb.density = 1.0f;
    rb.friction = 0.3f;
    rb.restitution = 0.5;
    rb.gravityScale = 0.1;
    rb.fixedRotation = true;

    NOOK::b2PolygonComponent rect;
    rect.width = 50.0f;
    rect.height = 40.0;

    NOOK::Shape shape;
    shape.isRectangle = true;
    shape.color = sf::Color::White;

    NOOK::RectangleShape rectangleShape;
    rectangleShape.width = 50.0f;
    rectangleShape.height = 40.0f;

    NOOK::Transform transform;

    gCoordinator.addComponent(box, rb);
    gCoordinator.addComponent(box, rect);
    gCoordinator.addComponent(box, shape);
    gCoordinator.addComponent(box, rectangleShape);
    gCoordinator.addComponent(box, transform);

    // Game loop
    // TODO: try to abstract this to a separate function

    sf::RenderWindow window;
    window.setFramerateLimit(config.FRAMES);
    sf::Clock clock;
    window.create(sf::VideoMode(config.WIDTH, config.HEIGHT), config.WINDOW_TITLE);

    // TODO: change awake implementation. Awake runs only in the first frame of the game
    int iteration = 0;
    while (window.isOpen()) {
        if (iteration < 1) {
            physicsSystem->awake(worldId);
            iteration++;
        }
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // TODO: could each system be on its own thread? Maybe not, because i need the physics transformations
        physicsSystem->update(worldId);
        movementSystem->update(&event);
        bouncePhysicsSystem->update();
        renderShapeSystem->update(&window);
        renderTextSystem->update(&window);
        renderSpriteSystem->update(&window);

        window.display();
    }
    return 0;
}