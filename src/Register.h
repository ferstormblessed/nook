//
// Created by stormblessed on 9/4/24.
//

#pragma once

#include "core/Coordinator.h"
#include "components/Gravity.h"
#include "components/RigidBody.h"
#include "components/Transform.h"
#include "components/Sprite.h"
#include "Systems/Render/RenderSystem.h"
#include "Systems/Physics/PhysicsSystem.h"
#include "Systems/Render/RenderShapeSystem.h"
#include "components/RectangleShape.h"
#include "Systems/Render/RenderTextSystem.h"
#include "components/Text.h"

extern NOOK::Coordinator gCoordinator;

namespace NOOK {

    void registerComponents() {
        // TODO: make function that reads directory components and extracts the name of each file and registers the component
        gCoordinator.registerComponent<NOOK::CircleShape>();
        gCoordinator.registerComponent<NOOK::Gravity>();
        gCoordinator.registerComponent<NOOK::RectangleShape>();
        gCoordinator.registerComponent<NOOK::RigidBody>();
        gCoordinator.registerComponent<NOOK::Shape>();
        gCoordinator.registerComponent<NOOK::Sprite>();
        gCoordinator.registerComponent<NOOK::Text>();
        gCoordinator.registerComponent<NOOK::Transform>();
    }

    std::shared_ptr<NOOK::RenderShapeSystem> registerRenderShapeSystem() {
        auto renderShapeSystem = gCoordinator.registerSystem<NOOK::RenderShapeSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Shape>());
            gCoordinator.setSystemSignature<NOOK::RenderShapeSystem>(signature);
        }
        return renderShapeSystem;
    }

    std::shared_ptr<NOOK::RenderTextSystem> registerRenderTextSystem() {
        auto renderTextSystem = gCoordinator.registerSystem<NOOK::RenderTextSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Text>());
            gCoordinator.setSystemSignature<NOOK::RenderTextSystem>(signature);
        }
        return renderTextSystem;
    }

    std::shared_ptr<NOOK::RenderSystem> registerRenderSystem() {
        auto renderSystem = gCoordinator.registerSystem<NOOK::RenderSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Sprite>());
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
}