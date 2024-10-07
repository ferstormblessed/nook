//
// Created by stormblessed on 9/8/24.
//

#include "MovementSystem.h"
#include "spdlog/spdlog.h"
#include "../core/Coordinator.h"
#include "../components/RigidBody.h"
#include "../Utils/utils.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::MovementSystem::init() {
    spdlog::info("initializing MOVEMENT SYSTEM");
}

void NOOK::MovementSystem::update(sf::Event* event) {
    if (sf::Event::KeyPressed != event->type) {
        return;
    }

    for (auto& entity : m_entities) {
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
        auto& playerMove = gCoordinator.getComponent<NOOK::PlayerMove>(entity);
        auto& rb = gCoordinator.getComponent<NOOK::RigidBody>(entity);

        moveWithKeyboard(rb, playerMove, event->key.code);
    }
}

void NOOK::MovementSystem::moveWithKeyboard(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key) {
    b2Vec2 velocity = b2Body_GetLinearVelocity(rb.bodyId);
    if (sf::Keyboard::isKeyPressed(key) && playerMove.up == key) {
        moveUp(rb, playerMove, key, velocity);
    }
    if (sf::Keyboard::isKeyPressed(key) && playerMove.down== key) {
        moveDown(rb, playerMove, key, velocity);
    }
    if (sf::Keyboard::isKeyPressed(key) && playerMove.right == key) {
        moveRight(rb, playerMove, key, velocity);
    }
    if (sf::Keyboard::isKeyPressed(key) && playerMove.left == key) {
        moveLeft(rb, playerMove, key, velocity);
    }
}

void NOOK::MovementSystem::moveUp(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key, b2Vec2& velocity) {
    velocity.y += playerMove.speed * b2Body_GetMass(rb.bodyId);
    b2Body_ApplyLinearImpulseToCenter(rb.bodyId, -velocity, true);

    if (velocity.y > 0.0f) {
        b2Body_SetLinearDamping(rb.bodyId,1);
    }
}
void NOOK::MovementSystem::moveDown(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key, b2Vec2& velocity) {
    velocity.y += playerMove.speed * b2Body_GetMass(rb.bodyId);
    b2Body_ApplyLinearImpulseToCenter(rb.bodyId, velocity, true);

    if (velocity.y > 0.0f) {
        b2Body_SetLinearDamping(rb.bodyId,1);
    }
}

void NOOK::MovementSystem::moveRight(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key, b2Vec2& velocity) {
    velocity.x += playerMove.speed * b2Body_GetMass(rb.bodyId);
    b2Body_ApplyLinearImpulseToCenter(rb.bodyId, -velocity, true);

    if (velocity.x > 0.0f) {
        b2Body_SetLinearDamping(rb.bodyId,1);
    }
}

void NOOK::MovementSystem::moveLeft(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key, b2Vec2& velocity) {
    velocity.x += playerMove.speed * b2Body_GetMass(rb.bodyId);
    b2Body_ApplyLinearImpulseToCenter(rb.bodyId, velocity, true);

    if (velocity.x > 0.0f) {
        b2Body_SetLinearDamping(rb.bodyId,1);
    }
}

