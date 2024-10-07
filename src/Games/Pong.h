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

    void paddles(const NOOK::Config& config) {
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
        l_rb.position = b2Vec2{30.f, config.HEIGHT / 2.f - 100};
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
        r_rb.position = b2Vec2{config.WIDTH - 50.f, config.HEIGHT/2.f - 100};
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

    void ball(const NOOK::Config& config) {
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
        // RigidBody component
        NOOK::RigidBody rigidBody;
        rigidBody.bodyType = b2_dynamicBody;
        rigidBody.position = b2Vec2{config.WIDTH/2.f - circleShape.radius, config.HEIGHT/2.f - circleShape.radius};
        rigidBody.shapeType = NOOK::b2Circle;
        rigidBody.density = 1.0f;
        rigidBody.restitution = 1.0f;
        rigidBody.gravityScale = 0.0;
        rigidBody.fixedRotation = true;
        rigidBody.initSpeed = b2Vec2{-5.0f, -5.0f};
        rigidBody.collidable = true;

        NOOK::b2CircleComponent circleComponent;
        circleComponent.radius = 10.0f;

        // Add components to Ball
        gCoordinator.addComponent(ball, shape);
        gCoordinator.addComponent(ball, circleShape);
        gCoordinator.addComponent(ball, transform);
        gCoordinator.addComponent(ball, rigidBody);
        gCoordinator.addComponent(ball, circleComponent);
    }

    void limits(const NOOK::Config& config) {
        NOOK::Entity up = gCoordinator.createEntity();
        NOOK::Entity down = gCoordinator.createEntity();

        // up components
        // Shape component
        NOOK::Shape up_shape;
        up_shape.isRectangle = true;
        up_shape.color = sf::Color::White;
        // RectangleShape component
        NOOK::RectangleShape up_rectShape;
        up_rectShape.height = 10.0f;
        up_rectShape.width = config.WIDTH;
        // Transform component
        NOOK::Transform up_transform;
        // RigidBody component
        NOOK::RigidBody up_rb;
        up_rb.bodyType = b2_staticBody;
        up_rb.position = b2Vec2{config.WIDTH / 2.0f, 10.0f};
        up_rb.shapeType = NOOK::b2Polygon;
        up_rb.density = 1.0f;
        up_rb.fixedRotation = true;
        up_rb.collidable = true;
        // b2RectangleComponent component
        NOOK::b2PolygonComponent up_polygon;
        up_polygon.height = 10.0f;
        up_polygon.width = config.WIDTH;

        // up components
        // Shape component
        NOOK::Shape down_shape;
        down_shape.isRectangle = true;
        down_shape.color = sf::Color::White;
        // RectangleShape component
        NOOK::RectangleShape down_rectShape;
        down_rectShape.height = 10.0f;
        down_rectShape.width = config.WIDTH;
        // Transform component
        NOOK::Transform down_transform;
        // RigidBody component
        NOOK::RigidBody down_rb;
        down_rb.bodyType = b2_staticBody;
        down_rb.position = b2Vec2{config.WIDTH / 2.0f, float(config.HEIGHT) - 10};
        down_rb.shapeType = NOOK::b2Polygon;
        down_rb.density = 1.0f;
        down_rb.fixedRotation = true;
        down_rb.collidable = true;
        // b2RectangleComponent component
        NOOK::b2PolygonComponent down_polygon;
        down_polygon.height = 10.0f;
        down_polygon.width = config.WIDTH;

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

    void Pong(const NOOK::Config& config) {
        paddles(config);
        ball(config);
        limits(config);
    }

} // NAMESPACE NOOK

#endif //NOOK_PONG_H
