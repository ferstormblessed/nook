//
// Created by stormblessed on 9/5/24.
//

#include "NOOK/core/Coordinator.h"
#include "NOOK/Systems/Render/RenderShapeSystem.h"
#include "NOOK/components/Transform.h"
#include <iostream>

extern NOOK::Coordinator gCoordinator;

void NOOK::RenderShapeSystem::init() {
    std::cout << "INFO: initializing RENDER SHAPE SYSTEM" << std::endl;
}

void NOOK::RenderShapeSystem::update(sf::RenderWindow *window) {
    for (auto& entity : m_entities) {
        drawShape(*window, entity);
    }
}

void NOOK::RenderShapeSystem::drawShape(sf::RenderWindow& window, const NOOK::Entity& entity) {
    auto& shape = gCoordinator.getComponent<NOOK::Shape>(entity);
    if (shape.isCircle) {
        drawCircleShape(window, entity, shape);
    }

    if (shape.isRectangle) {
        drawRectangleShape(window, entity, shape);
    }
}

void NOOK::RenderShapeSystem::initCircleShape(const NOOK::Entity& entity, NOOK::Shape& shape, NOOK::CircleShape& circleShape) {
    auto newShape = std::make_shared<sf::CircleShape>();

    if (*circleShape.radius <= 0) {
        std::cerr << "ERROR: Invalid radius magnitude: " << *circleShape.radius << std::endl;
        return;
    }

    // 2 because the function only works with 3 sides onwards
    if (*circleShape.numSides > 2) {
        newShape->setPointCount(*circleShape.numSides);
    }

    newShape->setRadius(*circleShape.radius);

    newShape->setFillColor(shape.color);
    newShape->setOutlineColor(shape.outlineColor);
    newShape->setOutlineThickness(*shape.outlineThickness);

    // TODO: handle textures for circle shapes

    circleShape.shape = newShape;
    shape.loaded = true;
}

void NOOK::RenderShapeSystem::drawCircleShape(sf::RenderWindow &window, const NOOK::Entity &entity, NOOK::Shape& shape) {
    auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
    auto& circleShape = gCoordinator.getComponent<CircleShape>(entity);

    // Detect change in data
    if (!shape.loaded) {
        initCircleShape(entity, shape, circleShape);
    }

    float x = transform.position.x - *circleShape.radius;
    float y = transform.position.y - *circleShape.radius;

    circleShape.shape->setPosition(x, y);

    window.draw(*circleShape.shape);
}

void NOOK::RenderShapeSystem::initRectangleShape(const NOOK::Entity& entity, NOOK::Shape& shape, NOOK::RectangleShape& rectangleShape) {
    auto newShape = std::make_shared<sf::RectangleShape>();

    if (*rectangleShape.height <= 0 || *rectangleShape.width <= 0) {
        std::cerr << "ERROR: Invalid rectangle dimensions: height=" << *rectangleShape.height << " width=" << *rectangleShape.width << std::endl;
        return;
    }

    newShape->setSize(sf::Vector2f(*rectangleShape.width, *rectangleShape.height));

    newShape->setFillColor(shape.color);
    newShape->setOutlineColor(shape.outlineColor);
    newShape->setOutlineThickness(*shape.outlineThickness);

    // TODO: handle textures for rectangle shapes

    rectangleShape.shape = newShape;
    shape.loaded = true;
}

void NOOK::RenderShapeSystem::drawRectangleShape(sf::RenderWindow &window, const NOOK::Entity &entity, NOOK::Shape& shape) {
    auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
    auto& rectangleShape = gCoordinator.getComponent<RectangleShape>(entity);

    if (!shape.loaded) {
        initRectangleShape(entity, shape, rectangleShape);
    }

    float x = transform.position.x - *rectangleShape.width / 2;
    float y = transform.position.y - *rectangleShape.height / 2;

    rectangleShape.shape->setPosition(x, y);

    window.draw(*rectangleShape.shape);
}