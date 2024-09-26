//
// Created by stormblessed on 9/20/24.
//

#include "BouncePhysicsSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::BouncePhysicsSystem::init() {
    spdlog::info("initializing BOUNCE PHYSICS SYSTEMS");
}

void NOOK::BouncePhysicsSystem::update() {
    for (auto& entity : m_entities) {
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
        auto& rigidBody = gCoordinator.getComponent<NOOK::RigidBody>(entity);
        move(transform, rigidBody);
    }
}

void NOOK::BouncePhysicsSystem::move(NOOK::Transform& transform, NOOK::RigidBody rigidBody) {
//    transform.position.x += rigidBody.body.linearVelocity.x;
//    transform.position.y += rigidBody.body.linearVelocity.y;
}