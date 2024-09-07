//
// Created by stormblessed on 7/17/24.
//

#pragma once

#ifndef NOOK_TRANSFORM_H
#define NOOK_TRANSFORM_H

#include <box2d/box2d.h>

namespace NOOK {

    struct Transform {
        b2Vec2 position{};
        b2Vec3 rotation{}; // vec(angle, xPos, yPos)
        b2Vec2 scale{}; // vec(scaleX, scaleY)
    };

} // NAMESPACE NOOK

#endif //NOOK_TRANSFORM_H
