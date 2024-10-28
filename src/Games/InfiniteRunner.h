#pragma once

#ifndef NOOK_INFINITERUNNER_H
#define NOOK_INFINITERUNNER_H

#include "../Config.h"
#include "../core/Types.h"
#include "../core/Coordinator.h"
#include "../components/Transform.h"
#include "../components/RigidBody.h"
#include "../components/Shape.h"
#include "../components/Sprite.h"
#include "../components/RectangleShape.h"
#include "../components/PlayerMove.h"
#include "../components/PhysicsPolygon.h"
#include "../components/Logic.h"
#include "../Utils/utils.h"
#include "../components/Text.h"
#include "imgui.h"
#include "../GUI/GameOverScreen.h"
#include "../GUI/PauseScreen.h"
#include "../components/GameOver.h"

extern NOOK::Coordinator gCoordinator;

namespace InfiniteRunner {

    // Global variables
    float width = 0.0f;
    float height = 0.0f;
    bool fixedRotation = true;
    bool isCollidable = true;
    float defaultFloat = 0.0f;
    bool defaultBool = false;

    // dinosaur variables
    float jumpForce = 2000.0f;
    float dinosaurDensity = 1.0f;
    float dinosaurGravityScale = 0.2f;
    float dinosaurHeight = 100.0f;
    float dinosaurWidth = 60.0f;

    // floor variables
    float floorHeight = 10.0f;
    float floorWidth = 2.0f * float(width);
    float floorDensity = 1.0f;

    // Score text variables
    int score = 0;
    std::string infiniteRunnerScoreText = std::to_string(score);
    std::string fontName = "font1";
    int fontSize = 70.0f;

    // obstacles variables
    float obstacleDensity = 1000.0f;
    float obstacleGravityScale = 0.2f;
    float obstacleHeight = 60.0f;
    float obstacleWidth = 80.0f;

    void gameOverFunction(const NOOK::Entity entity) {
        auto& gameOverComponent = gCoordinator.getComponent<NOOK::GameOver>(entity);
        if (gameOverComponent.isOver) {
            NOOK::GameOverScreen(gameOverComponent);
        }
    }

    void playAgainFunction(const NOOK::Entity entity) {
        auto& rb = gCoordinator.getComponent<NOOK::RigidBody>(entity);
        auto& gameOverComponent = gCoordinator.getComponent<NOOK::GameOver>(entity);

        if (gameOverComponent.playAgain) {
            gameOverComponent.playAgain = false;
            score = 0;
            b2Body_SetLinearVelocity(rb.bodyId,{0.0f, 0.0f});
            float x = NOOK::xCoordinatePixelToMetric(60.0f);
            float y = NOOK::yCoordinatePixelToMetric(0.0f);
            b2Body_SetTransform(rb.bodyId, {x, y}, b2Body_GetRotation(rb.bodyId));
        }

    }

    void gameLogicFunction(const NOOK::Entity entity) {
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
        auto& gameOverComponent = gCoordinator.getComponent<NOOK::GameOver>(entity);

        if (transform.position.x < 0.0f) {
            gameOverComponent.isOver = true;
        }
    }

    void pause(const NOOK::Entity entity) {
        auto& p = gCoordinator.getComponent<NOOK::Pause>(entity);
        NOOK::PauseScreen("P");
    }

    void Dinosaur() {
        NOOK::Entity dinosaur = gCoordinator.createEntity();

        // Transform
        NOOK::Transform transform;
        // Rigid body
        NOOK::RigidBody rb;
        rb.bodyType = b2_dynamicBody;
        rb.position = b2Vec2{60.0f, 0.0f};
        rb.shapeType = NOOK::b2Polygon;
        rb.density = &dinosaurDensity;
        rb.gravityScale = &dinosaurGravityScale;
        rb.fixedRotation = &fixedRotation;
        rb.collidable = &isCollidable;
        rb.friction = &defaultFloat;
        rb.restitution = &defaultFloat;
        // b2Polygon
        NOOK::PhysicsPolygon polygon;
        polygon.height = &dinosaurHeight;
        polygon.width = &dinosaurWidth;
        // Sprite
        NOOK::Sprite sprite;
        sprite.spriteName = "dino";
        sprite.height = &dinosaurHeight;
        sprite.width = &dinosaurWidth;
        // Player component
        NOOK::Jump jump;
        jump.jumpKey = sf::Keyboard::Key::Space;
        jump.force = &jumpForce;
        // Game Logic
        NOOK::Logic logic;
        logic.name = "dino";
        logic.gameLogicFunction = gameLogicFunction;
        // Pause
        NOOK::Pause p;
        p.pauseKey = sf::Keyboard::Key::P;
        p.onPauseFunction = pause;
        // Game Over
        NOOK::GameOver gameOver;
        gameOver.gameOverFunction = gameOverFunction;
        gameOver.playAgainFunction = playAgainFunction;
        // Debug
        NOOK::Debug debug;
        debug.toggleDebug = sf::Keyboard::Key::D;
        debug.type = NOOK::FLOAT;
        // debug float
        NOOK::FloatVariableDebug floatDebug;
        floatDebug.name = "Jump Force";
        floatDebug.value = &jumpForce;

        gCoordinator.addComponent(dinosaur, transform);
        gCoordinator.addComponent(dinosaur, rb);
        gCoordinator.addComponent(dinosaur, polygon);
        gCoordinator.addComponent(dinosaur, sprite);
        gCoordinator.addComponent(dinosaur, jump);
        gCoordinator.addComponent(dinosaur, logic);
        gCoordinator.addComponent(dinosaur, p);
        gCoordinator.addComponent(dinosaur, gameOver);
        gCoordinator.addComponent(dinosaur, debug);
        gCoordinator.addComponent(dinosaur, floatDebug);
    }

    void Floor() {
        NOOK::Entity floor = gCoordinator.createEntity();

        // Shape
        NOOK::Shape shape;
        shape.isRectangle = true;
        shape.color = sf::Color::White;
        shape.outlineThickness = &defaultFloat;
        // RectangleShape component
        NOOK::RectangleShape rectangleShape;
        rectangleShape.height = &floorHeight;
        rectangleShape.width = &floorWidth;
        // Transform component
        NOOK::Transform transform;
        // RigidBody component
        NOOK::RigidBody rb;
        rb.bodyType = b2_staticBody;
        rb.position = b2Vec2{width / 2.0f, 3.0f * height / 4.f - 20.0f};
        rb.shapeType = NOOK::b2Polygon;
        rb.density = &floorDensity;
        rb.fixedRotation = &fixedRotation;
        rb.collidable = &isCollidable;
        rb.friction = &defaultFloat;
        rb.gravityScale = &defaultFloat;
        rb.restitution = &defaultFloat;
        // b2RectangleComponent component
        NOOK::PhysicsPolygon polygon;
        polygon.height = &floorHeight;
        polygon.width = &floorWidth;

        gCoordinator.addComponent(floor, shape);
        gCoordinator.addComponent(floor, rectangleShape);
        gCoordinator.addComponent(floor, transform);
        gCoordinator.addComponent(floor, rb);
        gCoordinator.addComponent(floor, polygon);
    }

    void updateInfiniteRunnerScore(const NOOK::Entity entity) {
        auto& text = gCoordinator.getComponent<NOOK::Text>(entity);
        infiniteRunnerScoreText = std::to_string(score);
        text.text = &infiniteRunnerScoreText;
    }

    void InfiniteRunnerScore() {
        NOOK::Entity scoreText = gCoordinator.createEntity();
        // Text component
        NOOK::Text text;
        text.font = &fontName;
        text.text = &infiniteRunnerScoreText;
        text.size = &fontSize;
        text.color = sf::Color::White; float* outlineThickness{};
        text.lineSpacing = &defaultFloat;
        text.letterSpacing = &defaultFloat;
        text.isBold = &defaultBool;
        text.isItalic = &defaultBool;
        text.isUnderlined = &defaultBool;
        text.isStrikeThrough = &defaultBool;
        text.outlineThickness = &defaultFloat;
        // Transform component
        NOOK::Transform transform;
        transform.position = b2Vec2{width - 100.0f, 90.f};
        // Game Logic Component
        NOOK::Logic logic{};
        logic.gameLogicFunction = updateInfiniteRunnerScore;
        logic.name = "InfiniteRunnerTextScore";
        // Debug
        NOOK::Debug debug;
        debug.toggleDebug = sf::Keyboard::Key::D;
        debug.type = NOOK::INT;
        // Debug int
        NOOK::IntVariableDebug intDebug;
        intDebug.name = "Score";
        intDebug.value = &score;

        gCoordinator.addComponent(scoreText, text);
        gCoordinator.addComponent(scoreText, transform);
        gCoordinator.addComponent(scoreText, logic);
        gCoordinator.addComponent(scoreText, debug);
        gCoordinator.addComponent(scoreText, intDebug);
    }

    void ResetPosition(const NOOK::Entity entity) {
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
        auto& rb = gCoordinator.getComponent<NOOK::RigidBody>(entity);

        if (transform.position.x < -10.0f) {
            float x = NOOK::xCoordinatePixelToMetric( width + 50.0f);
            float y = b2Body_GetPosition(rb.bodyId).y;
            b2Body_SetTransform(rb.bodyId, {x, y}, b2Body_GetRotation(rb.bodyId));
            float velocityX = b2Body_GetLinearVelocity(rb.bodyId).x + 0.1f;
            b2Body_SetLinearVelocity(rb.bodyId, {velocityX, 0.0f});

            score++;
        }
    }

    void Cactus2() {
        NOOK::Entity cactus = gCoordinator.createEntity();
        // Transform
        NOOK::Transform transform;
        // RigidBody
        NOOK::RigidBody rb;
        rb.bodyType = b2_dynamicBody;
        rb.density = &obstacleDensity;
        rb.collidable = &isCollidable;
        rb.gravityScale = &obstacleGravityScale;
        rb.initSpeed = {-10.0f, 0.0f};
        rb.position = {width + 10.0f, 3 * height / 4.0f - 50.0f};
        rb.fixedRotation = &defaultBool;
        rb.friction = &defaultFloat;
        rb.restitution = &defaultFloat;
        // b2polygon
        NOOK::PhysicsPolygon polygon;
        polygon.height = &obstacleHeight;
        polygon.width = &obstacleWidth;
        // Sprite
        NOOK::Sprite sprite;
        sprite.spriteName = "cactus2";
        sprite.width = &obstacleWidth;
        sprite.height = &obstacleHeight;
        // Logic
        NOOK::Logic logic{};
        logic.name = "cactus";
        logic.gameLogicFunction = ResetPosition;

        gCoordinator.addComponent(cactus, rb);
        gCoordinator.addComponent(cactus, transform);
        gCoordinator.addComponent(cactus, polygon);
        gCoordinator.addComponent(cactus, sprite);
        gCoordinator.addComponent(cactus, logic);
    }

    void Cactus3() {
        NOOK::Entity cactus2 = gCoordinator.createEntity();
        // Transform
        NOOK::Transform transform;
        // RigidBody
        NOOK::RigidBody rb;
        rb.bodyType = b2_dynamicBody;
        rb.density = &obstacleDensity;
        rb.collidable = &isCollidable;
        rb.gravityScale = &obstacleGravityScale;
        rb.initSpeed = {-10.0f, 0.0f};
        rb.position = {width + width / 4.0f, 3 * height / 4.0f - 50.0f};
        rb.fixedRotation = &defaultBool;
        rb.friction = &defaultFloat;
        rb.restitution = &defaultFloat;
        // b2polygon
        NOOK::PhysicsPolygon polygon;
        polygon.height = &obstacleHeight;
        polygon.width = &obstacleWidth;
        // Sprite
        NOOK::Sprite sprite;
        sprite.spriteName = "cactus3";
        sprite.height = &obstacleHeight;
        sprite.width = &obstacleWidth;
        // Logic
        NOOK::Logic logic{};
        logic.name = "cactus";
        logic.gameLogicFunction = ResetPosition;

        gCoordinator.addComponent(cactus2, rb);
        gCoordinator.addComponent(cactus2, transform);
        gCoordinator.addComponent(cactus2, polygon);
        gCoordinator.addComponent(cactus2, sprite);
        gCoordinator.addComponent(cactus2, logic);
    }

    void Bird() {
        NOOK::Entity cactus2 = gCoordinator.createEntity();
        // Transform
        NOOK::Transform transform;
        // RigidBody
        NOOK::RigidBody rb;
        rb.bodyType = b2_dynamicBody;
        rb.density = &obstacleDensity;
        rb.collidable = &isCollidable;
        rb.gravityScale = &obstacleGravityScale;
        rb.initSpeed = {-10.0f, 0.0f};
        rb.position = {width + width / 2.0f, 3 * height / 4.0f - 50.0f};
        rb.fixedRotation = &defaultBool;
        rb.friction = &defaultFloat;
        rb.restitution = &defaultFloat;
        // b2polygon
        NOOK::PhysicsPolygon polygon;
        polygon.height = &obstacleHeight;
        polygon.width = &obstacleWidth;
        // Sprite
        NOOK::Sprite sprite;
        sprite.spriteName = "bird";
        sprite.height = &obstacleHeight;
        sprite.width = &obstacleWidth;
        // Logic
        NOOK::Logic logic{};
        logic.name = "cactus";
        logic.gameLogicFunction = ResetPosition;

        gCoordinator.addComponent(cactus2, rb);
        gCoordinator.addComponent(cactus2, transform);
        gCoordinator.addComponent(cactus2, polygon);
        gCoordinator.addComponent(cactus2, sprite);
        gCoordinator.addComponent(cactus2, logic);
    }

    void InfiniteRunner(const NOOK::Config &config) {
        height = float(config.HEIGHT);
        width = float(config.WIDTH);

        floorWidth = 2.0f * float(width);

        InfiniteRunnerScore();
        Floor();
        Dinosaur();
        Cactus2();
        Cactus3();
        Bird();
    }
}

#endif //NOOK_INFINITERUNNER_H