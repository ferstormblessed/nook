//
// Created by stormblessed on 7/28/24.
//

#include "../core/Coordinator.h"
#include "PhysicsSystem.h"
#include "spdlog/spdlog.h"
#include "../components/RigidBody.h"
#include "../components/Transform.h"
#include "../components/Gravity.h"

NOOK::PhysicsSystem::PhysicsSystem(const std::shared_ptr<Coordinator> &coordinator) : m_coordinator(coordinator) {}

void NOOK::PhysicsSystem::init() {
    spdlog::info("Initializing PHYSICS SYSTEM");
}

void NOOK::PhysicsSystem::update(float dt) {
    for (auto const& entity : m_entities) {
        auto& rigidBody = m_coordinator->getComponent<NOOK::RigidBody>(entity);
        auto& transform = m_coordinator->getComponent<NOOK::Transform>(entity);
        auto const& gravity = m_coordinator->getComponent<NOOK::Gravity>(entity);
    }
}