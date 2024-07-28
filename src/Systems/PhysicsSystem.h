//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_PHYSICSSYSTEM_H
#define NOOK_PHYSICSSYSTEM_H


#include "../core/System.h"

namespace NOOK {

    class PhysicsSystem : public System {
    public:
        explicit PhysicsSystem(const std::shared_ptr<Coordinator>& coordinator);
        void init();
        void update(float dt);
    private:
        std::shared_ptr<Coordinator> m_coordinator;
    };

} // NAMESPACE NOOK


#endif //NOOK_PHYSICSSYSTEM_H
