//
// Created by stormblessed on 11/9/24.
//

#pragma once

#ifndef NOOK_PLATFORMER_H
#define NOOK_PLATFORMER_H

#include "NOOK/core/Coordinator.h"
#include "NOOK/Utils/Config.h"
#include "NOOK/components/Shape.h"
#include "NOOK/components/Sprite.h"
#include "NOOK/components/Transform.h"
#include "NOOK/components/RigidBody.h"
#include "NOOK/components/PhysicsPolygon.h"
#include "NOOK/Utils/utils.h"
#include "NOOK/components/CircleShape.h"
#include "NOOK/components/PhysicsCircle.h"
#include "NOOK/components/Logic.h"

extern NOOK::Coordinator gCoordinator;

namespace Platformer {

    // Globals for all elements
    float width{};
    float height{};
    bool fixedRotation = true;
    bool isCollidable = true;
    float defaultFloat{};
    bool defaultBool{};

    // Platforms
    std::vector<std::string> textures = {"ice_texture", "mud_texture", "rock_texture"};
    std::vector<float> frictions = {0.0f, 0.5f, 1.0f};
    float tileHeight = 20.0f;
    float tileWidth = 150.0f;
    float tileDensity = 0.0;
    std::unordered_map<NOOK::Entity, b2Vec2> entityToPos;
    float platformSpeed = 1.0f;
    float platformRestitution = 1.0f;

    // player
    float playerFriction = 1.0f;
    float playerRestitution = 1.0f;
    float playerGravity = 0.5f;
    float playerRadius = 10.0f;
    int numSides = 100;
    float playerForce = 6000.0f;
    float playerDensity = 0.5f;
    float playerSpeed = 30.0f;

    // missiles
    float rocketWidth = 50.0f;
    float rocketHeight = 35.0f;
    float rocketSpeed = 10.0f;
    int numRockets = 10;

    void MovePlatform(NOOK::Entity entity) {
        auto& rb = gCoordinator.getComponent<NOOK::RigidBody>(entity);

        b2Vec2 pos = b2Body_GetPosition(rb.bodyId);
        b2Vec2 posPixel;
        posPixel.x = NOOK::xCoordinateMetricToPixel(pos.x);
        posPixel.y = NOOK::yCoordinateMetricToPixel(pos.y);

        b2Vec2 velocity = b2Body_GetLinearVelocity(rb.bodyId);
        float leftLimit = entityToPos[entity].x - tileWidth / 2.0f;
        float rightLimit = entityToPos[entity].x + tileWidth / 2.0f;

        if (posPixel.x <= leftLimit || posPixel.x >= rightLimit) {
            velocity.x = -velocity.x;
            b2Body_SetLinearVelocity(rb.bodyId, velocity); // Update the platform velocity
        }
    }

    void Platform(float posX, float posY, NOOK::Entity& entity, int direction) {
        // Sprite
        NOOK::Sprite sprite;
        sprite.height = &tileHeight;
        sprite.width = &tileWidth;
        int spritesLength = textures.size();
        int idxTexture = int(NOOK::randomFloat(0, spritesLength));
        sprite.spriteName = textures[idxTexture];

        // Transform
        NOOK::Transform transform;

        // RigidBody
        NOOK::RigidBody rb;
        rb.bodyType = b2_kinematicBody;
        rb.position = b2Vec2{posX, posY};
        rb.shapeType = NOOK::b2Polygon;
        rb.density = &tileDensity;
        rb.friction = &frictions[idxTexture];
        rb.restitution = &platformRestitution;
        rb.gravityScale = &defaultFloat;
        rb.fixedRotation = &fixedRotation;
        rb.collidable = &isCollidable;
        rb.initSpeed = {platformSpeed * direction, 0.0f};

        NOOK::PhysicsPolygon polygon;
        polygon.height = &tileHeight;
        polygon.width = &tileWidth;

        NOOK::Logic logic{};
        logic.gameLogicFunction = MovePlatform;

        gCoordinator.addComponent(entity, sprite);
        gCoordinator.addComponent(entity, transform);
        gCoordinator.addComponent(entity, rb);
        gCoordinator.addComponent(entity, polygon);
        gCoordinator.addComponent(entity, logic);
    }

    void Platforms() {
        int levels = 5;
        int platformsPerLevel = 4;

        float horizontalSpacing = (width - (platformsPerLevel * tileWidth)) / (platformsPerLevel + 1);
        float verticalSpacing = height / (levels + 1);
        float bottomOffset = height * 0.2f;
        float shiftRightOffset = width * 0.02f;
        b2Vec2 pos{};

        for (int i = 0; i < levels; i++) {
            for (int j = 0; j < platformsPerLevel; j++) {
                NOOK::Entity entity = gCoordinator.createEntity();
                int direction = NOOK::randomSign();

                pos.x = shiftRightOffset + horizontalSpacing + j * (tileWidth + horizontalSpacing);
                pos.y = bottomOffset + i * verticalSpacing;
                entityToPos[entity] = pos;

                Platform(pos.x, pos.y, entity, direction);
            }

        }
        pos.x = width / 2.0f;
        pos.y = 3.0f * tileHeight;
        NOOK::Entity winningPlatform = gCoordinator.createEntity();
        entityToPos[winningPlatform] = pos;
        Platform(pos.x, pos.y, winningPlatform, NOOK::randomSign());
    }

    void Player() {
        NOOK::Entity player = gCoordinator.createEntity();

        // Shape
        NOOK::Shape shape;
        shape.isCircle = true;
        shape.color = sf::Color::Red;
        shape.outlineThickness = &defaultFloat;

        // Circle shape
        NOOK::CircleShape circleShape;
        circleShape.numSides = &numSides;
        circleShape.radius = &playerRadius;

        // transform
        NOOK::Transform transform;

        // Rigid body
        NOOK::RigidBody rb;
        rb.bodyType = b2_dynamicBody;
        rb.position = b2Vec2{width / 2.0f, height * 0.75f};
        rb.shapeType = NOOK::b2Circle;
        rb.density = &playerDensity;
        rb.friction = &playerFriction;
        rb.restitution = &playerRestitution;
        rb.gravityScale = &playerGravity;
        rb.fixedRotation = &fixedRotation;
        rb.collidable = &isCollidable;

        // physics shape
        NOOK::PhysicsCircle physicsCircle;
        physicsCircle.radius = &playerRadius;

        // movement
        NOOK::PlayerMove move;
        move.left = sf::Keyboard::Key::Left;
        move.right = sf::Keyboard::Key::Right;
        move.speed = &playerSpeed;
        // jump
        NOOK::Jump jump;
        jump.force = &playerForce;
        jump.jumpKey = sf::Keyboard::Key::Space;

        gCoordinator.addComponent(player, shape);
        gCoordinator.addComponent(player, circleShape);
        gCoordinator.addComponent(player, transform);
        gCoordinator.addComponent(player, rb);
        gCoordinator.addComponent(player, physicsCircle);
        gCoordinator.addComponent(player, jump);
        gCoordinator.addComponent(player, move);
    }

    void ReSpawnRockets(NOOK::Entity entity) {
        auto& rb = gCoordinator.getComponent<NOOK::RigidBody>(entity);

        b2Vec2 pos{};
        pos.x = NOOK::xCoordinateMetricToPixel(b2Body_GetPosition(rb.bodyId).x);
        pos.y = NOOK::yCoordinateMetricToPixel(b2Body_GetPosition(rb.bodyId).y);

        if (pos.y < 0) {
            b2Vec2 vel;
            vel.x = 0.0f;
            vel.y = 0.0f;
            b2Body_SetLinearVelocity(rb.bodyId, vel);

            b2Vec2 position;
            position.x = b2Body_GetPosition(rb.bodyId).x;
            position.y = NOOK::yCoordinatePixelToMetric(height);
            b2Body_SetTransform(rb.bodyId, position, b2Body_GetRotation(rb.bodyId));

            vel.y = -rocketSpeed * NOOK::randomFloat(0.5f, 1);
            b2Body_SetLinearVelocity(rb.bodyId, vel);
        }
    }

    void Missile(float posX, float posY, NOOK::Entity& entity) {
        // Sprite
        NOOK::Sprite sprite;
        sprite.spriteName = "rocket";
        sprite.height = &rocketHeight;
        sprite.width = &rocketWidth;

        // transform
        NOOK::Transform transform;

        // rb
        NOOK::RigidBody rb;
        rb.bodyType = b2_kinematicBody;
        rb.position = b2Vec2{posX, posY};
        rb.shapeType = NOOK::b2Polygon;
        rb.density = &tileDensity;
        rb.friction = &defaultFloat;
        rb.restitution = &defaultFloat;
        rb.gravityScale = &defaultFloat;
        rb.fixedRotation = &fixedRotation;
        rb.collidable = &isCollidable;
        rb.initSpeed = {0.0f, -rocketSpeed * NOOK::randomFloat(0.5, 1)};

        // physics shape
        NOOK::PhysicsPolygon physicsPolygon;
        physicsPolygon.width = &rocketWidth;
        physicsPolygon.height = &rocketHeight;

        NOOK::Logic logic{};
        logic.gameLogicFunction = ReSpawnRockets;
        logic.name = "rocket";

        gCoordinator.addComponent(entity, sprite);
        gCoordinator.addComponent(entity, transform);
        gCoordinator.addComponent(entity, rb);
        gCoordinator.addComponent(entity, physicsPolygon);
        gCoordinator.addComponent(entity, logic);
    }

    void Missiles() {
        float horizontalSpacing = (width - (numRockets * rocketWidth)) / (numRockets + 1);
        for (int i = 0; i < numRockets; ++i) {
            float posX = horizontalSpacing + i * (rocketWidth + horizontalSpacing);
            float posY = height - rocketHeight;
            NOOK::Entity entity = gCoordinator.createEntity();
            Missile(posX, posY, entity);
        }
    }

    void Platformer(NOOK::Config& config) {
        width = config.WIDTH;
        height = config.HEIGHT;

        Platforms();
        Player();
        Missiles();
    }
}

#endif //NOOK_PLATFORMER_H
