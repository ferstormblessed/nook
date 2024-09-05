//
// Created by stormblessed on 7/28/24.
//

#include "RenderSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"
#include "../../components/Renderable.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::RenderSystem::init() {
    spdlog::info("initializing RENDER SYSTEM");
}

void NOOK::RenderSystem::update(sf::RenderWindow* window) {
    for (auto& entity : m_entities) {
        auto& renderable = gCoordinator.getComponent<NOOK::Renderable>(entity);

        if (renderable.isShape) {
            spdlog::info("drawing SHAPE");
            drawShape(*window, entity);
        }

        if (renderable.isSprite) {
            auto& render = gCoordinator.getComponent<NOOK::Sprite>(entity);
            auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);

            initSprite(render);

            render.sprite.setScale(transform.scale.x, transform.scale.y);
            render.sprite.setPosition(transform.position.x, transform.position.y);

            window->draw(render.sprite);
        }

        if (renderable.isText) {

        }
    }
}

void NOOK::RenderSystem::drawShape(sf::RenderWindow& window, const NOOK::Entity& entity) {
    auto& shape = gCoordinator.getComponent<NOOK::Shape>(entity);
    if (shape.isCircle) {
        spdlog::info("drawing CIRCLE");
        drawCircleShape(window, entity, shape);
    }

    if (shape.isRectangle) {
        drawRectangleShape(window, entity);
    }

    if (shape.isLine) {
        drawLineShape(window, entity);
    }
}

void NOOK::RenderSystem::drawCircleShape(sf::RenderWindow &window, const NOOK::Entity &entity, NOOK::Shape& shape) {
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

void NOOK::RenderSystem::drawRectangleShape(sf::RenderWindow &window, const NOOK::Entity &entity) {

}

void NOOK::RenderSystem::drawLineShape(sf::RenderWindow &window, const NOOK::Entity &entity) {

}

void NOOK::RenderSystem::initSprite(NOOK::Sprite& sprite) {
    if (sprite.loaded) {
        return;
    }
    if (sprite.image.empty()) {
       spdlog::error("NOT A VALID IMAGE STRING");
       return;
    }
    sprite.texture.loadFromFile(sprite.image);
    sprite.sprite.setTexture(sprite.texture);
    sprite.loaded = true;
}
