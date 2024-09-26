//
// Created by stormblessed on 9/20/24.
//

#pragma once

#ifndef NOOK_BOUNCEPHYSICSSYSTEM_H
#define NOOK_BOUNCEPHYSICSSYSTEM_H

#include "../../core/System.h"
#include "../../components/RigidBody.h"
#include "../../components/Transform.h"

namespace NOOK {

    class BouncePhysicsSystem : public System {
    public:
        void init();
        void update();
    private:
        void move(NOOK::Transform& transform, NOOK::RigidBody rigidBody);

    };

} // NAMESPACE NOOK


#endif //NOOK_BOUNCEPHYSICSSYSTEM_H
