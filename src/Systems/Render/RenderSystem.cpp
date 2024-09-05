//
// Created by stormblessed on 7/28/24.
//

#include "RenderSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::RenderSystem::init() {
    spdlog::info("initializing RENDER SYSTEM");
}

void NOOK::RenderSystem::update(sf::RenderWindow* window) {
    for (auto& entity : m_entities) {
        auto& render = gCoordinator.getComponent<NOOK::Sprite>(entity);
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);

        initSprite(render);

        render.sprite.setScale(transform.scale.x, transform.scale.y);
        render.sprite.setPosition(transform.position.x, transform.position.y);

        window->draw(render.sprite);
    }
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
