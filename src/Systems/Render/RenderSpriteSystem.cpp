//
// Created by stormblessed on 7/28/24.
//

#include "RenderSpriteSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"
#include "../../components/Transform.h"
#include "../../utils/utils.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::RenderSpriteSystem::init(const std::string& directory) {
    spdlog::info("initializing RENDER SPRITE SYSTEM");
    loadSprites(directory);
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

    if (sprite.spriteName.empty() || sprites.count(sprite.spriteName) == 0){
        spdlog::error("Not a valid sprite name");
        return;
    }

    sprite.sprite.setTexture(getTexture(sprite.spriteName));

    window.draw(sprite.sprite);
}

void NOOK::RenderSpriteSystem::loadSprites(const std::string &path) {
    std::vector<std::string> spriteFiles = NOOK::getFilesInDirectory(path);

    for (auto& file : spriteFiles) {
        std::string spriteName = NOOK::getFileNameWithoutExtension(file);
        sf::Texture texture;
        texture.loadFromFile(file);
        sprites[spriteName] = texture;
    }
}

sf::Texture NOOK::RenderSpriteSystem::getTexture(const std::string &spriteName) {
    // can just return, checked if the texture exist elsewhere
    return sprites[spriteName];
}