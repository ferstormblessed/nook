//
// Created by stormblessed on 9/25/24.
//

#pragma once

#ifndef NOOK_PHYSICSPOLYGON_H
#define NOOK_PHYSICSPOLYGON_H

#include "box2d/collision.h"

namespace NOOK {

    struct PhysicsPolygon {
        struct b2Polygon shape{};
        float width{};
        float height{};
    };

} // NAMESPACE NOOK

#endif //NOOK_PHYSICSPOLYGON_H
