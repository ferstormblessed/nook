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
#include "../Systems/Movement/MovementSystem.h"
#include "../components/b2CircleComponent.h"
#include "../components/b2PolygonComponent.h"
#include "../Systems/GameLogic/GameLogicSystem.h"
#include "../components/Logic.h"

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
        gCoordinator.registerComponent<NOOK::Logic>();
    }

    std::shared_ptr<NOOK::RenderShapeSystem> registerRenderShapeSystem() {
        auto renderShapeSystem = gCoordinator.registerSystem<NOOK::RenderShapeSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Shape>());
            signature.set(gCoordinator.getComponentType<NOOK::Transform>());
            gCoordinator.setSystemSignature<NOOK::RenderShapeSystem>(signature);
        }
        return renderShapeSystem;
    }

    std::shared_ptr<NOOK::RenderTextSystem> registerRenderTextSystem() {
        auto renderTextSystem = gCoordinator.registerSystem<NOOK::RenderTextSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Text>());
            signature.set(gCoordinator.getComponentType<NOOK::Transform>());
            gCoordinator.setSystemSignature<NOOK::RenderTextSystem>(signature);
        }
        return renderTextSystem;
    }

    std::shared_ptr<NOOK::RenderSpriteSystem> registerRenderSpriteSystem() {
        auto renderSystem = gCoordinator.registerSystem<NOOK::RenderSpriteSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Sprite>());
            signature.set(gCoordinator.getComponentType<NOOK::Transform>());
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
            signature.set(gCoordinator.getComponentType<NOOK::PlayerMove>());
            signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
            gCoordinator.setSystemSignature<NOOK::MovementSystem>(signature);
        }
        return movementSystem;
    }

    std::shared_ptr<NOOK::GameLogicSystem> registerGameLogicSystem() {
        auto gameLogicSystem = gCoordinator.registerSystem<NOOK::GameLogicSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Logic>());
            gCoordinator.setSystemSignature<NOOK::GameLogicSystem>(signature);
        }
        return gameLogicSystem;
    }

} // NAMESPACE NOOK