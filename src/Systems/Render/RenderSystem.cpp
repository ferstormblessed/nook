//
// Created by stormblessed on 7/28/24.
//

#include "RenderSystem.h"
#include "SFML/Graphics/Texture.hpp"

NOOK::RenderSystem::RenderSystem(const std::shared_ptr<Coordinator> &coordinator) : m_coordinator(coordinator) {}

void NOOK::RenderSystem::init() {
    for (auto const& entity : m_entities) {
        auto& render = m_coordinator->getComponent<NOOK::Render>(entity);
        initObject(render);
    }
}

void NOOK::RenderSystem::update() {
}

void NOOK::RenderSystem::initObject(NOOK::Render& object) {
    if (object.loaded) {
        return;
    }
    object.texture.loadFromFile(object.image);
    object.sprite.setTexture(object.texture);
}