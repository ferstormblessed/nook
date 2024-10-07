//
// Created by stormblessed on 9/19/24.
//

#pragma once

#ifndef NOOK_PONG_H
#define NOOK_PONG_H

#include "../core/Types.h"
#include "../core/Coordinator.h"
#include "../components/Shape.h"
#include "../components/RectangleShape.h"
#include "../components/Transform.h"
#include "../components/PlayerMove.h"
#include "../Config.h"
#include "../Utils/Register.h"

namespace NOOK {

    float width = 0;
    float height = 0;

    int scorePlayer1 = 0;
    int scorePlayer2 = 0;

    std::string player1ScoreName = "player1Score";
    std::string player2ScoreName = "player2Score";

    void paddles() {
        // Paddles
        NOOK::Entity l_paddle = gCoordinator.createEntity();
        NOOK::Entity r_paddle = gCoordinator.createEntity();

        // Left paddle components
        // Shape component
        NOOK::Shape l_shape;
        l_shape.isRectangle = true;
        l_shape.color = sf::Color::White;
        // RectangleShape component
        NOOK::RectangleShape l_rectangleShape;
        l_rectangleShape.height = 200.f;
        l_rectangleShape.width = 20.f;
        // Transform component
        NOOK::Transform l_transform;
        // PlayerMove component
        NOOK::PlayerMove l_playerMove;
        l_playerMove.speed = 10.f;
        l_playerMove.up = sf::Keyboard::Key::E;
        l_playerMove.down = sf::Keyboard::Key::U;
        // RigidBody component
        NOOK::RigidBody l_rb;
        l_rb.bodyType = b2_dynamicBody;
        l_rb.position = b2Vec2{30.f, height / 2.f - 100};
        l_rb.shapeType = NOOK::b2Polygon;
        l_rb.density = 1000.0f;
        l_rb.friction = 0.0f;
        l_rb.restitution = 0.0f;
        l_rb.gravityScale = 0.0f;
        l_rb.fixedRotation = true;
        l_rb.collidable = true;
        // TODO: try to combine/simplify the component for rendering shape and physics shape
        // b2RectangleComponent component
        NOOK::b2PolygonComponent l_polygon;
        l_polygon.height = 200.0f;
        l_polygon.width = 20.0f;

        // Right paddle components
        // Shape component
        NOOK::Shape r_shape;
        r_shape.isRectangle = true;
        r_shape.color = sf::Color::White;
        // RectangleShape component
        NOOK::RectangleShape r_rectangleShape;
        r_rectangleShape.height = 200.f;
        r_rectangleShape.width = 20.f;
        // Transform component
        NOOK::Transform r_transform;
        // PlayerMove component
        NOOK::PlayerMove r_playerMove;
        r_playerMove.speed = 10.f;
        r_playerMove.up = sf::Keyboard::Key::Up;
        r_playerMove.down = sf::Keyboard::Key::Down;
        // RigidBody component
        NOOK::RigidBody r_rb;
        r_rb.bodyType = b2_dynamicBody;
        r_rb.position = b2Vec2{width - 50.f, height/2.f - 100};
        r_rb.shapeType = NOOK::b2Polygon;
        r_rb.density = 1000.0f;
        r_rb.friction = 0.0f;
        r_rb.restitution = 0.0f;
        r_rb.gravityScale = 0.0f;
        r_rb.fixedRotation = true;
        r_rb.collidable = true;
        // TODO: try to combine/simplify the component for rendering shape and physics shape
        // b2RectangleComponent component
        NOOK::b2PolygonComponent r_polygon;
        r_polygon.height = 200.0f;
        r_polygon.width = 20.0f;

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

    void limits() {
        NOOK::Entity up = gCoordinator.createEntity();
        NOOK::Entity down = gCoordinator.createEntity();

        // up components
        // Shape component
        NOOK::Shape up_shape;
        up_shape.isRectangle = true;
        up_shape.color = sf::Color::White;
        up_shape.color.a = 100;
        // RectangleShape component
        NOOK::RectangleShape up_rectShape;
        up_rectShape.height = 10.0f;
        up_rectShape.width = width;
        // Transform component
        NOOK::Transform up_transform;
        // RigidBody component
        NOOK::RigidBody up_rb;
        up_rb.bodyType = b2_staticBody;
        up_rb.position = b2Vec2{width / 2.0f, 0.0f};
        up_rb.shapeType = NOOK::b2Polygon;
        up_rb.density = 1.0f;
        up_rb.fixedRotation = true;
        up_rb.collidable = true;
        // b2RectangleComponent component
        NOOK::b2PolygonComponent up_polygon;
        up_polygon.height = 10.0f;
        up_polygon.width = width;

        // up components
        // Shape component
        NOOK::Shape down_shape;
        down_shape.isRectangle = true;
        down_shape.color = sf::Color::White;
        down_shape.color.a = 100;
        // RectangleShape component
        NOOK::RectangleShape down_rectShape;
        down_rectShape.height = 10.0f;
        down_rectShape.width = width;
        // Transform component
        NOOK::Transform down_transform;
        // RigidBody component
        NOOK::RigidBody down_rb;
        down_rb.bodyType = b2_staticBody;
        down_rb.position = b2Vec2{width / 2.0f, float(height)};
        down_rb.shapeType = NOOK::b2Polygon;
        down_rb.density = 1.0f;
        down_rb.fixedRotation = true;
        down_rb.collidable = true;
        // b2RectangleComponent component
        NOOK::b2PolygonComponent down_polygon;
        down_polygon.height = 10.0f;
        down_polygon.width = width;

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
        Entity net = gCoordinator.createEntity();
        // Net components
        // Shape component
        NOOK::Shape shape;
        shape.isRectangle = true;
        shape.color = sf::Color::White;
        shape.color.a = 100;
        // RectangleShape component
        NOOK::RectangleShape rectangle;
        rectangle.height = height - 10.f;
        rectangle.width = 10.0f;
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
            score.text = std::to_string(scorePlayer1);
        }
        if (logic.name == player2ScoreName) {
            score.text = std::to_string(scorePlayer2);
        }
    }

    void score() {
        // Score texts
        NOOK::Entity textScorePlayer1 = gCoordinator.createEntity();
        NOOK::Entity textScorePlayer2 = gCoordinator.createEntity();

        // Text Score Player 1 components
        // Text component
        NOOK::Text text_player1;
        text_player1.font = "font1";
        text_player1.text = std::to_string(scorePlayer1);
        text_player1.size = 100;
        text_player1.color = sf::Color::White;
        // Transform component
        NOOK::Transform transform_1;
        transform_1.position = b2Vec2{width / 2.0f - text_player1.size, text_player1.size / 4.0f};
        // Game Logic Component
        NOOK::Logic logic1{};
        logic1.gameLogicFunction = updateScore;
        logic1.name = player1ScoreName;

        // Text Score Player 2 components
        // Text component
        NOOK::Text text_player2;
        text_player2.font = "font1";
        text_player2.text = std::to_string(scorePlayer2);
        text_player2.size = 100;
        text_player2.color = sf::Color::White;
        // Transform component
        NOOK::Transform transform_2;
        transform_2.position = b2Vec2{width / 2.0f + 30, text_player2.size / 4.0f};
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

        if (transform.position.x < 0) {
            scorePlayer2++;
            b2Body_SetLinearVelocity(rb.bodyId, b2Vec2{0, 0});
            b2Body_SetTransform(rb.bodyId, center, transform.rotation);
            b2Body_SetLinearVelocity(rb.bodyId, b2Vec2{randomFloat(5, 10), randomFloat(-10, -5)});
        }
        if(transform.position.x > width) {
            scorePlayer1++;
            b2Body_SetLinearVelocity(rb.bodyId, b2Vec2{0, 0});
            b2Body_SetTransform(rb.bodyId, center, transform.rotation);
            b2Body_SetLinearVelocity(rb.bodyId, b2Vec2{randomFloat(5, 10), randomFloat(-10, -5)});
        }
    }

    void initBall() {
        // Ball
        NOOK::Entity ball = gCoordinator.createEntity();
        // TODO: Abstract the creation of this type of primitives
        // TODO: a circle that can collide, get initial position, radius, etc.
        // Ball components
        // Shape component
        NOOK::Shape shape;
        shape.isCircle = true;
        shape.color = sf::Color::White;
        // CircleShape component
        NOOK::CircleShape circleShape;
        circleShape.radius = 10.f;
        circleShape.numSides = 100;
        // Transform component
        NOOK::Transform transform;
        // Set velocities array
        int numVelocities = 5;
        // RigidBody component
        NOOK::RigidBody rigidBody;
        rigidBody.bodyType = b2_dynamicBody;
        rigidBody.position = b2Vec2{width / 2.0f - circleShape.radius, height / 2.f - circleShape.radius};
        rigidBody.shapeType = NOOK::b2Circle;
        rigidBody.density = 1.0f;
        rigidBody.restitution = 1.0f;
        rigidBody.gravityScale = 0.0;
        rigidBody.fixedRotation = true;
        rigidBody.initSpeed = b2Vec2{-NOOK::randomFloat(5.0f, 8.0f), NOOK::randomFloat(5.0f, 8.f)};
        rigidBody.collidable = true;
        // b2CircleComponent component
        NOOK::b2CircleComponent circleComponent;
        circleComponent.radius = 10.0f;
        // Game Logic component
        NOOK::Logic logic{};
        logic.gameLogicFunction = updateBall;

        // Add components to Ball
        gCoordinator.addComponent(ball, shape);
        gCoordinator.addComponent(ball, circleShape);
        gCoordinator.addComponent(ball, transform);
        gCoordinator.addComponent(ball, rigidBody);
        gCoordinator.addComponent(ball, circleComponent);
        gCoordinator.addComponent(ball, logic);
    }

    void Pong(const NOOK::Config& config) {
        width = float(config.WIDTH);
        height = float(config.HEIGHT);

        limits();
        net();
        score();

        paddles();
        initBall();
    }

} // NAMESPACE NOOK

#endif //NOOK_PONG_H
