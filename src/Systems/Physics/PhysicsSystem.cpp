//
// Created by stormblessed on 7/28/24.
//

#include "../../core/Coordinator.h"
#include "PhysicsSystem.h"
#include "spdlog/spdlog.h"
#include "../../components/RigidBody.h"
#include "../../components/Transform.h"
#include "../../components/Gravity.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::PhysicsSystem::init() {
    spdlog::info("initializing PHYSICS SYSTEM");
}

void NOOK::PhysicsSystem::update(float dt) {
    for (auto const& entity : m_entities) {
        auto& rigidBody = gCoordinator.getComponent<NOOK::RigidBody>(entity);
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
        auto const& gravity = gCoordinator.getComponent<NOOK::Gravity>(entity);

        transform.position.x += rigidBody.body.linearVelocity.x * dt;
        transform.position.y += rigidBody.body.linearVelocity.y * dt;

        rigidBody.body.linearVelocity.x += gravity.force.x * dt;
        rigidBody.body.linearVelocity.y += gravity.force.y * dt;
    }
}