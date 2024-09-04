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
        auto& render = gCoordinator.getComponent<NOOK::Render>(entity);
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);

        initObject(render);
        render.sprite.setScale(transform.scale.x, transform.scale.y);
        render.sprite.setPosition(transform.position.x, transform.position.y);
        spdlog::warn("RENDER SYSTEM INFO");
        spdlog::warn("Transform position: ({}, {})", transform.position.x, transform.position.y);
        spdlog::warn("Sprite position: ({}, {})", render.sprite.getPosition().x, render.sprite.getPosition().y);
        window->draw(render.sprite);
    }
}

void NOOK::RenderSystem::initObject(NOOK::Render& render) {
    if (render.loaded) {
        return;
    }
    if (render.image.empty()) {
       spdlog::error("Not a valid image string");
       return;
    }
    render.texture.loadFromFile(render.image);
    render.sprite.setTexture(render.texture);
    render.loaded = true;
}