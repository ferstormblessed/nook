//
// Created by stormblessed on 9/25/24.
//

#pragma once

#ifndef NOOK_B2CIRCLECOMPONENT_H
#define NOOK_B2CIRCLECOMPONENT_H

#include "box2d/collision.h"

namespace NOOK {

    struct b2CircleComponent {
        struct b2Circle shape{};
        float radius{};
    };

} // NAMESPACE NOOK

#endif //NOOK_B2CIRCLECOMPONENT_H
