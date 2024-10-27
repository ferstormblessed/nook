//
// Created by stormblessed on 7/28/24.
//

#include "RenderSpriteSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"
#include "../../core/ResourceManager.h"
#include "../../components/Sprite.h"
#include "../../components/Transform.h"

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

void initSprite(NOOK::Sprite& sprite) {
    if (sprite.spriteName.empty() || resourceManager.getTexture(sprite.spriteName) == nullptr){
        spdlog::error("Not a valid sprite name: {}", sprite.spriteName);
        return;
    }
    sprite.sprite.setTexture(*resourceManager.getTexture(sprite.spriteName));
    float scaleX = sprite.width / resourceManager.getTexture(sprite.spriteName)->getSize().x;
    float scaleY = sprite.height / resourceManager.getTexture(sprite.spriteName)->getSize().y;
    sprite.sprite.setScale(scaleX, scaleY);
    sprite.loaded = true;
}

void NOOK::RenderSpriteSystem::renderSprite(sf::RenderWindow &window, const NOOK::Entity &entity) {
    auto& sprite = gCoordinator.getComponent<NOOK::Sprite>(entity);
    auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);

    if (!sprite.loaded) {
        initSprite(sprite);
    }

    float x = transform.position.x - sprite.sprite.getGlobalBounds().width / 2;
    float y = transform.position.y - sprite.sprite.getGlobalBounds().height / 2;
    sprite.sprite.setPosition(x, y);
    window.draw(sprite.sprite);
}