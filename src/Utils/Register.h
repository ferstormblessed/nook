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
#include "../components/PhysicsCircle.h"
#include "../components/PhysicsPolygon.h"
#include "../Systems/GameLogic/GameLogicSystem.h"
#include "../components/Logic.h"
#include "../Systems/Movement/JumpSystem.h"
#include "../components/Jump.h"
#include "../components/Pause.h"
#include "../Systems/GameLogic/PauseSystem.h"
#include "../components/GameOver.h"
#include "../Systems/GameLogic/GameOverSystem.h"
#include "../components/IntVariableDebug.h"
#include "../components/FloatVariableDebug.h"
#include "../components/BoolVariableDebug.h"
#include "../Systems/Debug/DebugSystem.h"
#include "../components/Debug.h"

extern NOOK::Coordinator gCoordinator;

namespace NOOK {

    void registerComponents() {
        // TODO: make function that reads directory components and extracts the name of each file and registers the component
        gCoordinator.registerComponent<NOOK::PhysicsCircle>();
        gCoordinator.registerComponent<NOOK::PhysicsPolygon>();
        gCoordinator.registerComponent<NOOK::CircleShape>();
        gCoordinator.registerComponent<NOOK::PlayerMove>();
        gCoordinator.registerComponent<NOOK::RectangleShape>();
        gCoordinator.registerComponent<NOOK::RigidBody>();
        gCoordinator.registerComponent<NOOK::Shape>();
        gCoordinator.registerComponent<NOOK::Sprite>();
        gCoordinator.registerComponent<NOOK::Text>();
        gCoordinator.registerComponent<NOOK::Transform>();
        gCoordinator.registerComponent<NOOK::Logic>();
        gCoordinator.registerComponent<NOOK::Jump>();
        gCoordinator.registerComponent<NOOK::Pause>();
        gCoordinator.registerComponent<NOOK::GameOver>();
        gCoordinator.registerComponent<NOOK::Debug>();
        gCoordinator.registerComponent<NOOK::IntVariableDebug>();
        gCoordinator.registerComponent<NOOK::FloatVariableDebug>();
        gCoordinator.registerComponent<NOOK::BoolVariableDebug>();
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

    std::shared_ptr<NOOK::JumpSystem> registerJumpSystem() {
        auto jumpSystem = gCoordinator.registerSystem<NOOK::JumpSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Jump>());
            signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
            gCoordinator.setSystemSignature<NOOK::JumpSystem>(signature);
        }
        return jumpSystem;
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

    std::shared_ptr<NOOK::PauseSystem> registerPauseSystem() {
        auto pauseSystem = gCoordinator.registerSystem<NOOK::PauseSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Pause>());
            gCoordinator.setSystemSignature<NOOK::PauseSystem>(signature);
        }
        return pauseSystem;
    }

    std::shared_ptr<NOOK::GameOverSystem> registerGameOverSystem() {
        auto gameOverSystem = gCoordinator.registerSystem<NOOK::GameOverSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::GameOver>());
            gCoordinator.setSystemSignature<NOOK::GameOverSystem>(signature);
        }
        return gameOverSystem;
    }

    std::shared_ptr<NOOK::DebugSystem> registerDebugSystem() {
        auto debugSystem = gCoordinator.registerSystem<NOOK::DebugSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Debug>());
            gCoordinator.setSystemSignature<NOOK::DebugSystem>(signature);
        }
        return debugSystem;
    }

} // NAMESPACE NOOK