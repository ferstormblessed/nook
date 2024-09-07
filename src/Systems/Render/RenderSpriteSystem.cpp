//
// Created by stormblessed on 7/28/24.
//

#include "RenderSpriteSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"
#include "../../components/Transform.h"
#include "../../Utils//utils.h"
#include "../../core/ResourceManager.h"

extern NOOK::Coordinator gCoordinator;
extern NOOK::ResourceManager resourceManager;

void NOOK::RenderSpriteSystem::init() {
    spdlog::info("initializing RENDER SPRITE SYSTEM");
}

void NOOK::RenderSpriteSystem::update(sf::RenderWindow* window) {
    for (auto& entity : m_entities) {
        renderSprite(*window, entity);
    }
}

void NOOK::RenderSpriteSystem::renderSprite(sf::RenderWindow &window, const NOOK::Entity &entity) {
    // make render and transformations in separate functions
    auto& sprite = gCoordinator.getComponent<NOOK::Sprite>(entity);
    //auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);

    if (sprite.spriteName.empty() || resourceManager.getTexture(sprite.spriteName) == nullptr){
        spdlog::error("Not a valid sprite name: {}", sprite.spriteName);
        return;
    }

    sprite.sprite.setTexture(*resourceManager.getTexture(sprite.spriteName));

    window.draw(sprite.sprite);
}