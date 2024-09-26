//
// Created by stormblessed on 7/26/24.
//

#pragma once

#ifndef NOOK_SYSTEM_H
#define NOOK_SYSTEM_H

#include <set>
#include "Types.h"

namespace NOOK {

    class System {
    public:
        // TODO: Explain why set, reason: stored in contiguous memory, can make use of cache locality
        std::set<NOOK::Entity> m_entities;
    };

} // NAMESPACE NOOK

#endif //NOOK_SYSTEM_H
