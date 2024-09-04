//
// Created by stormblessed on 7/28/24.
//

#include "RenderSystem.h"
#include "spdlog/spdlog.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::RenderSystem::init() {
    for (auto const& entity : m_entities) {
        auto& render = gCoordinator.getComponent<NOOK::Render>(entity);
        initObject(render);
    }
}

void NOOK::RenderSystem::update() {
    for (auto& entity : m_entities) {
        auto& renderComponent = gCoordinator.getComponent<NOOK::Render>(entity);
    }
}

void NOOK::RenderSystem::initObject(NOOK::Render& object) {
    if (object.loaded) {
        return;
    }
    if (object.image.empty()) {
       spdlog::error("Not a valid image string");
       return;
    }
    object.texture.loadFromFile(object.image);
    object.sprite.setTexture(object.texture);
}