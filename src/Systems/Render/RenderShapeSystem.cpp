//
// Created by stormblessed on 9/5/24.
//

#include "RenderShapeSystem.h"
#include "../../components/CircleShape.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"

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
        drawRectangleShape(window, entity);
    }

    if (shape.isLine) {
        drawLineShape(window, entity);
    }
}

void NOOK::RenderShapeSystem::drawCircleShape(sf::RenderWindow &window, const NOOK::Entity &entity, NOOK::Shape& shape) {
    auto& circleShape = gCoordinator.getComponent<CircleShape>(entity);
    sf::CircleShape newShape;
    if (circleShape.numSides != 0) {
        newShape.setRadius(circleShape.radius);
        newShape.setPointCount(circleShape.numSides);
    }
    newShape.setRadius(circleShape.radius);

    newShape.setFillColor(shape.color);
    newShape.setOutlineColor(shape.outlineColor);
    newShape.setOutlineThickness(shape.outlineThickness);

    // TODO: handle textures

    window.draw(newShape);
}

void NOOK::RenderShapeSystem::drawRectangleShape(sf::RenderWindow &window, const NOOK::Entity &entity) {

}

void NOOK::RenderShapeSystem::drawLineShape(sf::RenderWindow &window, const NOOK::Entity &entity) {

}