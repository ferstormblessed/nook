//
// Created by stormblessed on 9/4/24.
//

#pragma once

#include "core/Coordinator.h"
#include "components/Gravity.h"
#include "components/RigidBody.h"
#include "components/Transform.h"
#include "components/Render.h"
#include "Systems/Render/RenderSystem.h"
#include "Systems/Physics/PhysicsSystem.h"

extern NOOK::Coordinator gCoordinator;

void registerComponents() {
    // TODO: make function that reads directory components and extracts the name of each file and registers the component
    gCoordinator.registerComponent<NOOK::Gravity>();
    gCoordinator.registerComponent<NOOK::RigidBody>();
    gCoordinator.registerComponent<NOOK::Transform>();
    gCoordinator.registerComponent<NOOK::Render>();
}

std::shared_ptr<NOOK::RenderSystem> registerRenderSystem() {
    auto renderSystem = gCoordinator.registerSystem<NOOK::RenderSystem>();
    {
        NOOK::Signature signature;
        signature.set(gCoordinator.getComponentType<NOOK::Render>());
        signature.set(gCoordinator.getComponentType<NOOK::Transform>());
        gCoordinator.setSystemSignature<NOOK::RenderSystem>(signature);
    }
    return renderSystem;
}

std::shared_ptr<NOOK::PhysicsSystem> registerPhysicsSystem() {
    auto physicsSystem = gCoordinator.registerSystem<NOOK::PhysicsSystem>();
    {
        NOOK::Signature signature;
        signature.set(gCoordinator.getComponentType<NOOK::Transform>());
        signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
        signature.set(gCoordinator.getComponentType<NOOK::Gravity>());
        gCoordinator.setSystemSignature<NOOK::PhysicsSystem>(signature);
    }
    return physicsSystem;
}
