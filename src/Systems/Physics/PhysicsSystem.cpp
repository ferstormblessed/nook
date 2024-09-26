//
// Created by stormblessed on 7/28/24.
//

#include "../../core/Coordinator.h"
#include "PhysicsSystem.h"
#include "spdlog/spdlog.h"
#include "../../components/RigidBody.h"
#include "../../Utils/utils.h"
#include "box2d/box2d.h"
#include "../../components/b2CircleComponent.h"
#include "../../components/b2PolygonComponent.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::PhysicsSystem::init() {
    spdlog::info("initializing PHYSICS SYSTEM");
}

void NOOK::PhysicsSystem::awake(b2WorldId& world) {
    for (auto& entity : m_entities) {
        initRigidBody(world, entity);
    }
}

void NOOK::PhysicsSystem::initRigidBody(b2WorldId& world, const NOOK::Entity& entity) {
    auto& rigidBody = gCoordinator.getComponent<NOOK::RigidBody>(entity);
    rigidBody.bodyDef = b2DefaultBodyDef();
    rigidBody.bodyDef.type = rigidBody.bodyType;

    float xCoordinate = NOOK::xCoordinatePixelToMetric(rigidBody.position.x);
    float yCoordinate = NOOK::yCoordinatePixelToMetric(rigidBody.position.y);
    rigidBody.bodyDef.position = b2Vec2{xCoordinate, yCoordinate};


    rigidBody.bodyId = b2CreateBody(world, &rigidBody.bodyDef);

    rigidBody.shapeDef = b2DefaultShapeDef();
    rigidBody.shapeDef.density = rigidBody.density;
    rigidBody.shapeDef.friction = rigidBody.friction;
    rigidBody.shapeDef.restitution = rigidBody.restitution;

    if (rigidBody.shapeType == NOOK::b2Circle) {
        auto& b2CircleComponent = gCoordinator.getComponent<NOOK::b2CircleComponent>(entity);
        float radius = NOOK::pixelToMetric(b2CircleComponent.radius);
        b2CircleComponent.shape.radius = radius;

        b2CreateCircleShape(rigidBody.bodyId, &rigidBody.shapeDef, &b2CircleComponent.shape);
    }

    if (rigidBody.shapeType == NOOK::b2Polygon) {
        auto& b2PolygonComponent = gCoordinator.getComponent<NOOK::b2PolygonComponent>(entity);
        // b2MakeBox function takes half height and width
        float x = NOOK::pixelToMetric(b2PolygonComponent.width) / 2;
        float y = NOOK::pixelToMetric(b2PolygonComponent.height) / 2;
        b2PolygonComponent.shape = b2MakeBox(x, y);

        b2CreatePolygonShape(rigidBody.bodyId, &rigidBody.shapeDef,&b2PolygonComponent.shape);
    }
}

void NOOK::PhysicsSystem::update(b2WorldId& world) {
    int subStepCount = 4; // Library value
    float timeStep = 1.0f / 60.0f; // Library value
    b2World_Step(world, timeStep, subStepCount);
    for (auto& entity : m_entities) {
        auto& rigidBody = gCoordinator.getComponent<NOOK::RigidBody>(entity);
        b2Vec2 position = b2Body_GetPosition(rigidBody.bodyId);
        b2Rot rotation = b2Body_GetRotation(rigidBody.bodyId);
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, b2Rot_GetAngle(rotation));
    }
}