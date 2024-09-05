//
// Created by stormblessed on 9/5/24.
//

#include "RenderShapeSystem.h"
#include "../../components/CircleShape.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "../../components/RectangleShape.h"
#include "SFML/Graphics/RectangleShape.hpp"

extern NOOK::Coordinator gCoordinator;

void NOOK::RenderShapeSystem::init() {
    spdlog::info("initializing RENDER SHAPE SYSTEM");
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

void NOOK::RenderShapeSystem::drawCircleShape(sf::RenderWindow &window, const NOOK::Entity &entity, NOOK::Shape& shape) {
    auto& circleShape = gCoordinator.getComponent<CircleShape>(entity);
    sf::CircleShape newShape;

    if (circleShape.radius <= 0) {
        spdlog::error("Invalid radius magnitude: {}", circleShape.radius);
        return;
    }

    // 2 because the function only works with 3 sides onwards
    if (circleShape.numSides > 2) {
        newShape.setPointCount(circleShape.numSides);
    }

    newShape.setRadius(circleShape.radius);

    newShape.setFillColor(shape.color);
    newShape.setOutlineColor(shape.outlineColor);
    newShape.setOutlineThickness(shape.outlineThickness);

    // TODO: handle textures for circle shapes

    window.draw(newShape);
}

void NOOK::RenderShapeSystem::drawRectangleShape(sf::RenderWindow &window, const NOOK::Entity &entity, NOOK::Shape& shape) {
    auto& rectangleShape = gCoordinator.getComponent<RectangleShape>(entity);
    sf::RectangleShape newShape;

    if (rectangleShape.height <= 0 || rectangleShape.width <= 0) {
        spdlog::error("Invalid rectangle dimensions: {} {}", rectangleShape.height, rectangleShape.width);
        return;
    }

    newShape.setSize(sf::Vector2f(rectangleShape.width, rectangleShape.height));

    newShape.setFillColor(shape.color);
    newShape.setOutlineColor(shape.outlineColor);
    newShape.setOutlineThickness(shape.outlineThickness);

    // TODO: handle textures for rectangle shapes

    window.draw(newShape);
}