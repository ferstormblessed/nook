//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_RIGIDBODY_H
#define NOOK_RIGIDBODY_H

#include "box2d/b2_body.h"

namespace NOOK {

    struct RigidBody {
        b2BodyDef body;
    };

} // NAMESPACE NOOK

#endif //NOOK_RIGIDBODY_H
