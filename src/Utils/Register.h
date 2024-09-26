//
// Created by stormblessed on 9/4/24.
//

#pragma once

#include "../core/Coordinator.h"
#include "../components/RigidBody.h"
#include "../components/Transform.h"
#include "../components/Sprite.h"
#include "../Systems/Render/RenderSpriteSystem.h"
#include "../Systems/Physics/PhysicsSystem.h"
#include "../Systems/Render/RenderShapeSystem.h"
#include "../components/RectangleShape.h"
#include "../Systems/Render/RenderTextSystem.h"
#include "../components/Text.h"
#include "../components/CircleShape.h"
#include "../components/PlayerMove.h"
#include "../Systems/MovementSystem.h"
#include "../Systems/Physics/BouncePhysicsSystem.h"
#include "../components/b2CircleComponent.h"
#include "../components/b2PolygonComponent.h"

extern NOOK::Coordinator gCoordinator;

namespace NOOK {

    void registerComponents() {
        // TODO: make function that reads directory components and extracts the name of each file and registers the component
        gCoordinator.registerComponent<NOOK::b2CircleComponent>();
        gCoordinator.registerComponent<NOOK::b2PolygonComponent>();
        gCoordinator.registerComponent<NOOK::CircleShape>();
        gCoordinator.registerComponent<NOOK::PlayerMove>();
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

    std::shared_ptr<NOOK::RenderSpriteSystem> registerRenderSpriteSystem() {
        auto renderSystem = gCoordinator.registerSystem<NOOK::RenderSpriteSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Sprite>());
            gCoordinator.setSystemSignature<NOOK::RenderSpriteSystem>(signature);
        }
        return renderSystem;
    }

    std::shared_ptr<NOOK::PhysicsSystem> registerPhysicsSystem() {
        auto physicsSystem = gCoordinator.registerSystem<NOOK::PhysicsSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
            gCoordinator.setSystemSignature<NOOK::PhysicsSystem>(signature);
        }
        return physicsSystem;
    }

    std::shared_ptr<NOOK::MovementSystem> registerMovementSystem() {
        auto movementSystem = gCoordinator.registerSystem<NOOK::MovementSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Transform>());
            signature.set(gCoordinator.getComponentType<NOOK::PlayerMove>());
            gCoordinator.setSystemSignature<NOOK::MovementSystem>(signature);
        }
        return movementSystem;
    }

    std::shared_ptr<NOOK::BouncePhysicsSystem> registerBouncePhysicsSystem() {
        auto bouncePhysicsSystem = gCoordinator.registerSystem<NOOK::BouncePhysicsSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Transform>());
            signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
            gCoordinator.setSystemSignature<NOOK::BouncePhysicsSystem>(signature);
        }
        return bouncePhysicsSystem;
    }

} // NAMESPACE NOOK