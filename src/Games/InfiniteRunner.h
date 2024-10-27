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

float w = 0.0f;
float h = 0.0f;
std::string infinitRunnerScore = "InfiniteRunnerScoreText";
int score = 0;

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
    rb.density = 1.0f;
    rb.gravityScale = 0.2f;
    rb.fixedRotation = true;
    rb.collidable = true;
    // b2Polygon
    NOOK::PhysicsPolygon polygon;
    polygon.height = 100.0f;
    polygon.width = 60.0f;
    // Sprite
    NOOK::Sprite sprite;
    sprite.spriteName = "dino";
    sprite.height = 100.0f;
    sprite.width = 60.0f;
    // Player component
    NOOK::Jump jump;
    jump.jumpKey = sf::Keyboard::Key::Space;
    jump.force = 2000.0f;
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

    gCoordinator.addComponent(dinosaur, transform);
    gCoordinator.addComponent(dinosaur, rb);
    gCoordinator.addComponent(dinosaur, polygon);
    gCoordinator.addComponent(dinosaur, sprite);
    gCoordinator.addComponent(dinosaur, jump);
    gCoordinator.addComponent(dinosaur, logic);
    gCoordinator.addComponent(dinosaur, p);
    gCoordinator.addComponent(dinosaur, gameOver);
}

void Floor() {
    NOOK::Entity floor = gCoordinator.createEntity();

    // Shape
    NOOK::Shape shape;
    shape.isRectangle = true;
    shape.color = sf::Color::White;
    // RectangleShape component
    NOOK::RectangleShape rectangleShape;
    rectangleShape.height = 20.0f;
    rectangleShape.width = 2.0f * w;
    // Transform component
    NOOK::Transform transform;
    // RigidBody component
    NOOK::RigidBody rb;
    rb.bodyType = b2_staticBody;
    rb.position = b2Vec2{w / 2.0f, 3.0f * h / 4.f - 20.0f};
    rb.shapeType = NOOK::b2Polygon;
    rb.density = 1.0f;
    rb.fixedRotation = true;
    rb.collidable = true;
    // b2RectangleComponent component
    NOOK::PhysicsPolygon polygon;
    polygon.height = 20.0f;
    polygon.width = 2.0f * w;

    gCoordinator.addComponent(floor, shape);
    gCoordinator.addComponent(floor, rectangleShape);
    gCoordinator.addComponent(floor, transform);
    gCoordinator.addComponent(floor, rb);
    gCoordinator.addComponent(floor, polygon);
}

void updateInfiniteRunnerScore(const NOOK::Entity entity) {
    auto& text = gCoordinator.getComponent<NOOK::Text>(entity);
    text.text = std::to_string(score);
}

void InfiniteRunnerScore() {
    NOOK::Entity scoreText = gCoordinator.createEntity();
    // Text component
    NOOK::Text text;
    text.font = "font1";
    text.text = std::to_string(score);
    text.size = 70;
    text.color = sf::Color::White;
    // Transform component
    NOOK::Transform transform;
    transform.position = b2Vec2{w - 100.0f, 90.f};
    // Game Logic Component
    NOOK::Logic logic{};
    logic.gameLogicFunction = updateInfiniteRunnerScore;
    logic.name = infinitRunnerScore;

    gCoordinator.addComponent(scoreText, text);
    gCoordinator.addComponent(scoreText, transform);
    gCoordinator.addComponent(scoreText, logic);
}

void ResetPosition(const NOOK::Entity entity) {
    auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
    auto& rb = gCoordinator.getComponent<NOOK::RigidBody>(entity);

    if (transform.position.x < -10.0f) {
        float x = NOOK::xCoordinatePixelToMetric(w + 30.0f);
        float y = b2Body_GetPosition(rb.bodyId).y;
        b2Body_SetTransform(rb.bodyId, {x, y}, b2Body_GetRotation(rb.bodyId));
        float velocityX = b2Body_GetLinearVelocity(rb.bodyId).x + 0.1f;
        float velocityY = b2Body_GetLinearVelocity(rb.bodyId).y;
        b2Body_SetLinearVelocity(rb.bodyId, {velocityX, velocityY});

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
    rb.density = 1000.0f;
    rb.collidable = true;
    rb.gravityScale = 0.2f;
    rb.initSpeed = {-10.0f, 0.0f};
    rb.position = {w + 10.0f, 3 * h / 4.0f - 50.0f};
    // b2polygon
    NOOK::PhysicsPolygon polygon;
    polygon.width = 80.0f;
    polygon.height = 60.0f;
    // Sprite
    NOOK::Sprite sprite;
    sprite.spriteName = "cactus2";
    sprite.width = 80.0f;
    sprite.height = 60.0f;
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
    rb.density = 1000.0f;
    rb.collidable = true;
    rb.gravityScale = 0.2f;
    rb.initSpeed = {-10.0f, 0.0f};
    rb.position = {w + w / 4.0f, 3 * h / 4.0f - 50.0f};
    // b2polygon
    NOOK::PhysicsPolygon polygon;
    polygon.width = 80.0f;
    polygon.height = 60.0f;
    // Sprite
    NOOK::Sprite sprite;
    sprite.spriteName = "cactus3";
    sprite.width = 80.0f;
    sprite.height = 60.0f;
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
    rb.density = 1000.0f;
    rb.collidable = true;
    rb.gravityScale = 0.2f;
    rb.initSpeed = {-10.0f, 0.0f};
    rb.position = {w + w / 2.0f, 3 * h / 4.0f - 50.0f};
    // b2polygon
    NOOK::PhysicsPolygon polygon;
    polygon.width = 80.0f;
    polygon.height = 60.0f;
    // Sprite
    NOOK::Sprite sprite;
    sprite.spriteName = "bird";
    sprite.width = 80.0f;
    sprite.height = 60.0f;
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
    w = float(config.WIDTH);
    h = float(config.HEIGHT);

    InfiniteRunnerScore();
    Floor();
    Dinosaur();
    Cactus2();
    Cactus3();
    Bird();
}

#endif //NOOK_INFINITERUNNER_H