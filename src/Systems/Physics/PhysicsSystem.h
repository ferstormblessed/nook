//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_PHYSICSSYSTEM_H
#define NOOK_PHYSICSSYSTEM_H


#include "../../core/System.h"
#include "box2d/id.h"

namespace NOOK {

    class PhysicsSystem : public System {
    public:
        void init();
        void update(b2WorldId& worldId);
        void awake(b2WorldId& world);
    private:
        void initRigidBody(b2WorldId& world, const NOOK::Entity& entity);
    };

} // NAMESPACE NOOK


#endif //NOOK_PHYSICSSYSTEM_H
