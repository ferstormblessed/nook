//
// Created by stormblessed on 7/17/24.
//

#pragma once

#ifndef NOOK_TYPES_H
#define NOOK_TYPES_H

#include <cstdint>
#include <bitset>

namespace NOOK {

    // ECS

    // Entity
    using Entity = std::uint32_t;
    const Entity MAX_ENTITIES = 100000;
    // Component
    using ComponentType = std::uint8_t;
    const ComponentType MAK_COMPONENTS = 200;
    // Signature
    // way to track which components an entity “has”, way to track which components a system cares about.
    // example
    // Components -- ID
    // Transform  -- 0
    // RigidBody  -- 1
    // Render     -- 2
    // SignatureOfEntity = 0...111
    // Signature length in bits is equal to MAX_COMPONENTS
    // And that's how we know which Components belong to specific Entity
    using Signature = std::bitset<MAK_COMPONENTS>;

} // NAMESPACE NOOK

#endif //NOOK_TYPES_H
