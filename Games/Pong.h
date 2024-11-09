//
// Created by stormblessed on 9/19/24.
//

#pragma once

#ifndef NOOK_PONG_H
#define NOOK_PONG_H


#include "NOOK/GUI/Screens.h"

namespace Pong {

    // Globals for all elements
    float width = 0;
    float height = 0;
    bool fixedRotation = true;
    bool isCollidable = true;
    float defaultFloat = 0.0f;
    bool defaultBool = false;

    // paddle variables
    float paddleHeight = 200.0f;
    float paddleWidth = 20.0f;
    float paddleDensity = 1000.0f;
    float playerSpeed = 10.0f;

    // limits variables
    float limitHeight = 10.0f;
    float limitWidth = width;
    float limitDensity = 1.0f;

    // net variables
    float netHeight = height - 10.0f;
    float netWidth = 10.0f;

    // Score text variables
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;
    std::string player1ScoreName = "player1Score";
    std::string player2ScoreName = "player2Score";
    std::string scorePlayer1Text = std::to_string(scorePlayer1);
    std::string scorePlayer2Text = std::to_string(scorePlayer2);
    std::string fontName = "font1";
    int fontSize = 100.0f;

    // ball variables
    float circleRadius = 10.0f;
    int circleSides = 100;
    float ballDensity = 1.0f;
    float ballRestitution = 1.0f;
    float ballGravityScale = 0.0f;

    void paddles() {
        // Paddles
        NOOK::Entity l_paddle = gCoordinator.createEntity();
        NOOK::Entity r_paddle = gCoordinator.createEntity();

        // Left paddle components
        // Shape component
        NOOK::Shape l_shape;
        l_shape.isRectangle = true;
        l_shape.color = sf::Color::White;
        l_shape.outlineThickness = &defaultFloat;
        // RectangleShape component
        NOOK::RectangleShape l_rectangleShape;
        l_rectangleShape.height = &paddleHeight;
        l_rectangleShape.width = &paddleWidth;
        // Transform component
        NOOK::Transform l_transform;
        // PlayerMove component
        NOOK::PlayerMove l_playerMove;
        l_playerMove.speed = &playerSpeed;
        l_playerMove.up = sf::Keyboard::Key::E;
        l_playerMove.down = sf::Keyboard::Key::U;
        // RigidBody component
        NOOK::RigidBody l_rb;
        l_rb.bodyType = b2_dynamicBody;
        l_rb.position = b2Vec2{30.f, height / 2.0f - 100.0f};
        l_rb.shapeType = NOOK::b2Polygon;
        l_rb.density = &paddleDensity;
        l_rb.friction = &defaultFloat;
        l_rb.restitution = &defaultFloat;
        l_rb.gravityScale = &defaultFloat;
        l_rb.fixedRotation = &fixedRotation;
        l_rb.collidable = &isCollidable;
        // b2RectangleComponent component
        NOOK::PhysicsPolygon l_polygon;
        l_polygon.height = &paddleHeight;
        l_polygon.width = &paddleWidth;

        // Right paddle components
        // Shape component
        NOOK::Shape r_shape;
        r_shape.isRectangle = true;
        r_shape.color = sf::Color::White;
        r_shape.outlineThickness = &defaultFloat;
        // RectangleShape component
        NOOK::RectangleShape r_rectangleShape;
        r_rectangleShape.height = &paddleHeight;
        r_rectangleShape.width = &paddleWidth;
        // Transform component
        NOOK::Transform r_transform;
        // PlayerMove component
        NOOK::PlayerMove r_playerMove;
        r_playerMove.speed = &playerSpeed;
        r_playerMove.up = sf::Keyboard::Key::Up;
        r_playerMove.down = sf::Keyboard::Key::Down;
        // RigidBody component
        NOOK::RigidBody r_rb;
        r_rb.bodyType = b2_dynamicBody;
        r_rb.position = b2Vec2{width - 50.f, height/2.0f - 100.0f};
        r_rb.shapeType = NOOK::b2Polygon;
        r_rb.density = &paddleDensity;
        r_rb.friction = &defaultFloat;
        r_rb.restitution = &defaultFloat;
        r_rb.gravityScale = &defaultFloat;
        r_rb.fixedRotation = &fixedRotation;
        r_rb.collidable = &isCollidable;
        // b2RectangleComponent component
        NOOK::PhysicsPolygon r_polygon;
        r_polygon.height = &paddleHeight;
        r_polygon.width = &paddleWidth;

        // Add components to Left paddle
        gCoordinator.addComponent(l_paddle, l_shape);
        gCoordinator.addComponent(l_paddle, l_rectangleShape);
        gCoordinator.addComponent(l_paddle, l_transform);
        gCoordinator.addComponent(l_paddle, l_playerMove);
        gCoordinator.addComponent(l_paddle, l_rb);
        gCoordinator.addComponent(l_paddle, l_polygon);
        // Add components to Right paddle
        gCoordinator.addComponent(r_paddle, r_shape);
        gCoordinator.addComponent(r_paddle, r_rectangleShape);
        gCoordinator.addComponent(r_paddle, r_transform);
        gCoordinator.addComponent(r_paddle, r_playerMove);
        gCoordinator.addComponent(r_paddle, r_rb);
        gCoordinator.addComponent(r_paddle, r_polygon);
    }

    void debugPaddleSpeed() {
        NOOK::Entity debugPaddleSpeed = gCoordinator.createEntity();

        // Debug
        NOOK::Debug debug;
        debug.type = NOOK::FLOAT;
        debug.toggleDebug = sf::Keyboard::Key::D;
        // Debug float
        NOOK::FloatVariableDebug speedDebug;
        speedDebug.name = "paddle speed";
        speedDebug.value = &playerSpeed;

        gCoordinator.addComponent(debugPaddleSpeed, debug);
        gCoordinator.addComponent(debugPaddleSpeed, speedDebug);
    }

    void limits() {
        NOOK::Entity up = gCoordinator.createEntity();
        NOOK::Entity down = gCoordinator.createEntity();

        // up components
        // Shape component
        NOOK::Shape up_shape;
        up_shape.isRectangle = true;
        up_shape.color = sf::Color::White;
        up_shape.color.a = 100;
        up_shape.outlineThickness = &defaultFloat;
        // RectangleShape component
        NOOK::RectangleShape up_rectShape;
        up_rectShape.height = &limitHeight;
        up_rectShape.width = &limitWidth;
        // Transform component
        NOOK::Transform up_transform;
        // RigidBody component
        NOOK::RigidBody up_rb;
        up_rb.bodyType = b2_staticBody;
        up_rb.position = b2Vec2{width / 2.0f, 0.0f};
        up_rb.shapeType = NOOK::b2Polygon;
        up_rb.density = &limitDensity;
        up_rb.fixedRotation = &fixedRotation;
        up_rb.collidable = &isCollidable;
        up_rb.friction = &defaultFloat;
        up_rb.restitution = &defaultFloat;
        up_rb.gravityScale = &defaultFloat;
        // b2RectangleComponent component
        NOOK::PhysicsPolygon up_polygon;
        up_polygon.height = &limitHeight;
        up_polygon.width = &limitWidth;

        // up components
        // Shape component
        NOOK::Shape down_shape;
        down_shape.isRectangle = true;
        down_shape.color = sf::Color::White;
        down_shape.color.a = 100;
        down_shape.outlineThickness = &defaultFloat;
        // RectangleShape component
        NOOK::RectangleShape down_rectShape;
        down_rectShape.height = &limitHeight;
        down_rectShape.width = &limitWidth;
        // Transform component
        NOOK::Transform down_transform;
        // RigidBody component
        NOOK::RigidBody down_rb;
        down_rb.bodyType = b2_staticBody;
        down_rb.position = b2Vec2{width / 2.0f, float(height)};
        down_rb.shapeType = NOOK::b2Polygon;
        down_rb.density = &limitDensity;
        down_rb.fixedRotation = &fixedRotation;
        down_rb.collidable = &isCollidable;
        down_rb.friction = &defaultFloat;
        down_rb.restitution = &defaultFloat;
        down_rb.gravityScale = &defaultFloat;
        // b2RectangleComponent component
        NOOK::PhysicsPolygon down_polygon;
        down_polygon.height = &limitHeight;
        down_polygon.width = &limitWidth;

        gCoordinator.addComponent(up, up_shape);
        gCoordinator.addComponent(up, up_rectShape);
        gCoordinator.addComponent(up, up_transform);
        gCoordinator.addComponent(up, up_rb);
        gCoordinator.addComponent(up, up_polygon);

        gCoordinator.addComponent(down, down_shape);
        gCoordinator.addComponent(down, down_rectShape);
        gCoordinator.addComponent(down, down_transform);
        gCoordinator.addComponent(down, down_rb);
        gCoordinator.addComponent(down, down_polygon);
    }

    void net() {
        // Creat net component
        NOOK::Entity net = gCoordinator.createEntity();
        // Net components
        // Shape component
        NOOK::Shape shape;
        shape.isRectangle = true;
        shape.color = sf::Color::White;
        shape.color.a = 100;
        shape.outlineThickness = &defaultFloat;
        // RectangleShape component
        NOOK::RectangleShape rectangle;
        rectangle.height = &netHeight;
        rectangle.width = &netWidth;
        // Transform component
        NOOK::Transform transform;
        transform.position = b2Vec2{width / 2.0f, height / 2.0f};

        gCoordinator.addComponent(net, shape);
        gCoordinator.addComponent(net, rectangle);
        gCoordinator.addComponent(net, transform);
    }

    void updateScore(const NOOK::Entity entity) {
        auto& score = gCoordinator.getComponent<NOOK::Text>(entity);
        auto& logic = gCoordinator.getComponent<NOOK::Logic>(entity);
        if (logic.name == player1ScoreName) {
            scorePlayer1Text = std::to_string(scorePlayer1);
            score.text = &scorePlayer1Text;
        }
        if (logic.name == player2ScoreName) {
            scorePlayer2Text = std::to_string(scorePlayer2);
            score.text = &scorePlayer2Text;
        }
    }

    void scoreText() {
        // Score texts
        NOOK::Entity textScorePlayer1 = gCoordinator.createEntity();
        NOOK::Entity textScorePlayer2 = gCoordinator.createEntity();

        // Text Score Player 1 components
        // Text component
        NOOK::Text text_player1;
        text_player1.font = &fontName;
        text_player1.text = &scorePlayer1Text;
        text_player1.size = &fontSize;
        text_player1.color = sf::Color::White;
        text_player1.outlineThickness = &defaultFloat;
        text_player1.lineSpacing = &defaultFloat;
        text_player1.letterSpacing = &defaultFloat;
        text_player1.isBold = &defaultBool;
        text_player1.isItalic = &defaultBool;
        text_player1.isUnderlined = &defaultBool;
        text_player1.isStrikeThrough = &defaultBool;
        // Transform component
        NOOK::Transform transform_1;
        transform_1.position = b2Vec2{width / 2.0f - float(fontSize), float(fontSize) / 4.0f};
        // Game Logic Component
        NOOK::Logic logic1{};
        logic1.gameLogicFunction = updateScore;
        logic1.name = player1ScoreName;

        // Text Score Player 2 components
        // Text component
        NOOK::Text text_player2;
        text_player2.font = &fontName;
        text_player2.text = &scorePlayer2Text;
        text_player2.size = &fontSize;
        text_player2.color = sf::Color::White;
        text_player2.outlineThickness = &defaultFloat;
        text_player2.lineSpacing = &defaultFloat;
        text_player2.letterSpacing = &defaultFloat;
        text_player2.isBold = &defaultBool;
        text_player2.isItalic = &defaultBool;
        text_player2.isUnderlined = &defaultBool;
        text_player2.isStrikeThrough = &defaultBool;
        // Transform component
        NOOK::Transform transform_2;
        transform_2.position = b2Vec2{width / 2.0f + 30, float(fontSize) / 4.0f};
        // Game Logic Component
        NOOK::Logic logic2{};
        logic2.gameLogicFunction = updateScore;
        logic2.name = player2ScoreName;

        gCoordinator.addComponent(textScorePlayer1, text_player1);
        gCoordinator.addComponent(textScorePlayer1, transform_1);
        gCoordinator.addComponent(textScorePlayer1, logic1);

        gCoordinator.addComponent(textScorePlayer2, text_player2);
        gCoordinator.addComponent(textScorePlayer2, transform_2);
        gCoordinator.addComponent(textScorePlayer2, logic2);
    }

    void updateBall(const NOOK::Entity entity) {
        auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);
        auto& rb = gCoordinator.getComponent<NOOK::RigidBody>(entity);

        float x = NOOK::xCoordinatePixelToMetric(width / 2);
        float y = NOOK::yCoordinatePixelToMetric(height / 2);
        b2Vec2 center = {x, y};

        int direction = NOOK::randomSign();
        float xMagnitude = direction * NOOK::randomFloat(10.0f, 15.0f);
        float yMagnitude = direction * NOOK::randomFloat(10.0f, 15.0f);
        if (transform.position.x < 0) {
            scorePlayer2++;
            b2Body_SetLinearVelocity(rb.bodyId, b2Vec2{0, 0});
            b2Body_SetTransform(rb.bodyId, center, transform.rotation);
            b2Body_SetLinearVelocity(rb.bodyId, b2Vec2{xMagnitude, yMagnitude});
        }
        if(transform.position.x > width) {
            scorePlayer1++;
            b2Body_SetLinearVelocity(rb.bodyId, b2Vec2{0, 0});
            b2Body_SetTransform(rb.bodyId, center, transform.rotation);
            b2Body_SetLinearVelocity(rb.bodyId, b2Vec2{xMagnitude, yMagnitude});
        }
    }

    void initBall() {
        // Ball
        NOOK::Entity ball = gCoordinator.createEntity();
        // Ball components
        // Shape component
        NOOK::Shape shape;
        shape.isCircle = true;
        shape.color = sf::Color::White;
        shape.outlineThickness = &defaultFloat;
        // CircleShape component
        NOOK::CircleShape circleShape;
        circleShape.radius = &circleRadius;
        circleShape.numSides = &circleSides;
        // Transform component
        NOOK::Transform transform;
        // RigidBody component
        NOOK::RigidBody rb;
        rb.bodyType = b2_dynamicBody;
        rb.position = b2Vec2{width / 2.0f - circleRadius, height / 2.f - circleRadius};
        rb.shapeType = NOOK::b2Circle;
        rb.density = &ballDensity;
        rb.restitution = &ballRestitution;
        rb.gravityScale = &ballGravityScale;
        rb.fixedRotation = &fixedRotation;
        rb.initSpeed = b2Vec2{NOOK::randomSign() * NOOK::randomFloat(10.0f, 15.0f), NOOK::randomSign() * NOOK::randomFloat(10.0f, 15.f)};
        rb.collidable = &isCollidable;
        rb.friction = &defaultFloat;
        // PhysicsCircle component
        NOOK::PhysicsCircle circleComponent;
        circleComponent.radius = &circleRadius;
        // Game Logic component
        NOOK::Logic logic{};
        logic.gameLogicFunction = updateBall;

        // Add components to Ball
        gCoordinator.addComponent(ball, shape);
        gCoordinator.addComponent(ball, circleShape);
        gCoordinator.addComponent(ball, transform);
        gCoordinator.addComponent(ball, rb);
        gCoordinator.addComponent(ball, circleComponent);
        gCoordinator.addComponent(ball, logic);
    }

    void onPauseFunction(const NOOK::Entity entity) {
        NOOK::PauseScreen("P");
    }

    void pauseGame() {
        NOOK::Entity pause = gCoordinator.createEntity();

        // Pause
        NOOK::Pause p;
        p.pauseKey = sf::Keyboard::Key::P;
        p.onPauseFunction = onPauseFunction;

        gCoordinator.addComponent(pause, p);
    }

    void Pong(const NOOK::Config& config) {
        width = float(config.WIDTH);
        height = float(config.HEIGHT);

        limitWidth = width;
        netHeight = height - 10.0f;

        initBall();
        limits();
        net();
        scoreText();
        paddles();
        pauseGame();
        debugPaddleSpeed();
    }
}

#endif //NOOK_PONG_H