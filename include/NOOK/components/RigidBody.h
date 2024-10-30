//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_RIGIDBODY_H
#define NOOK_RIGIDBODY_H


#include "box2d/types.h"

namespace NOOK {

    enum shape {
        b2Polygon,
        b2Circle
    };

    struct RigidBody {
        b2BodyDef bodyDef{};
        b2BodyType bodyType{};
        b2Vec2 position{};
        b2BodyId bodyId{};
        shape shapeType{};
        b2ShapeDef shapeDef{};
        float* density{};
        float* friction{};
        float* restitution{};
        float* gravityScale{};
        bool* fixedRotation{};
        b2Vec2 initSpeed{};
        bool* collidable{};
    };

} // NAMESPACE NOOK

#endif //NOOK_RIGIDBODY_H
