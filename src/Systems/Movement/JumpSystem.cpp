//
// Created by stormblessed on 10/27/24.
//

#include "JumpSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"
#include "box2d/box2d.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::JumpSystem::init() {
    spdlog::info("initializing JUMP SYSTEM");
}

void NOOK::JumpSystem::update(sf::Event *event, const GAME_STATE& gameState) {
    if (gameState != NOOK::PLAY_STATE) {
        return;
    }
    if (sf::Event::KeyPressed != event->type) {
        return;
    }
    for (auto& entity : m_entities) {
        auto& jumpComponent = gCoordinator.getComponent<NOOK::Jump>(entity);
        auto& rb = gCoordinator.getComponent<NOOK::RigidBody>(entity);

        jump(rb, jumpComponent, event->key.code);
    }
}

void NOOK::JumpSystem::jump(NOOK::RigidBody &rb, const NOOK::Jump &jump, const sf::Keyboard::Key &key) {
    if (sf::Keyboard::isKeyPressed(key) && jump.jumpKey == key) {
        b2Vec2 force = {0.0f, -*jump.force * b2Body_GetMass(rb.bodyId)};
        b2Body_ApplyForceToCenter(rb.bodyId, force, true);
    }
}
