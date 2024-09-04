//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_PHYSICSSYSTEM_H
#define NOOK_PHYSICSSYSTEM_H


#include "../../core/System.h"

namespace NOOK {

    class PhysicsSystem : public System {
    public:
        void init();
        void update(float dt);
    };

} // NAMESPACE NOOK


#endif //NOOK_PHYSICSSYSTEM_H
