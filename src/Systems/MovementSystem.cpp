//
// Created by stormblessed on 9/8/24.
//

#include "MovementSystem.h"
#include "spdlog/spdlog.h"
#include "../core/Coordinator.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::MovementSystem::init() {
    spdlog::info("initializing MovementSystem");
}


void NOOK::MovementSystem::update(sf::Event* event) {
    if (sf::Event::KeyPressed != event->type) {
        return;
    }

    for (auto& entity : m_entities) {
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
        auto& playerMove = gCoordinator.getComponent<NOOK::PlayerMove>(entity);

        moveWithKeyboard(transform, playerMove, event->key.code);
    }
}

void NOOK::MovementSystem::moveWithKeyboard(NOOK::Transform& transform, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key) {
    if (playerMove.up == key) {
        transform.position.y += 1 * playerMove.speed;
    }

    if (playerMove.down == key) {
        transform.position.y -= 1 * playerMove.speed;
    }

    if (playerMove.right == key) {
        transform.position.x += 1 * playerMove.speed;
    }

    if (playerMove.left == key) {
        transform.position.x -= 1 * playerMove.speed;
    }
}
