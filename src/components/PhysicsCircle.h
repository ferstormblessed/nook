//
// Created by stormblessed on 9/25/24.
//

#pragma once

#ifndef NOOK_PHYSICSCIRCLE_H
#define NOOK_PHYSICSCIRCLE_H

#include "box2d/collision.h"

namespace NOOK {

    struct PhysicsCircle {
        struct b2Circle shape{};
        float radius{};
    };

} // NAMESPACE NOOK

#endif //NOOK_PHYSICSCIRCLE_H
