//
// Created by stormblessed on 7/17/24.
//
#pragma once

#ifndef NOOK_ENTITYMAP_H
#define NOOK_ENTITYMAP_H

#include <cstdint>
#include <map>
#include <array>
#include "Entity.h"

namespace NOOK {

    const uint32_t MAX_NUMBER_COMPONENTS = 1024;
    using ComponentInstance = uint32_t;

    class EntityMap {
    private:
        std::map<Entity, ComponentInstance> entityToInstance;
        std::array<Entity, MAX_NUMBER_COMPONENTS> instanceToEntity;
    public:
        Entity getEntity(const ComponentInstance& component);
        ComponentInstance getInstance(const Entity& entity);
        void add(const Entity& entity, const ComponentInstance& instance);
        void update(const Entity& entity, const ComponentInstance& instance);
        void remove(const Entity& entity);
    };

} // NAMESPACE NOOK

#endif //NOOK_ENTITYMAP_H
