//
// Created by stormblessed on 7/17/24.
//

#pragma once

#ifndef NOOK_COMPONENTMANAGER_H
#define NOOK_COMPONENTMANAGER_H

#include <cstdint>
#include <array>
#include <map>
#include "Entity.h"
#include "EntityMap.h"

namespace NOOK {
    template<typename ComponentType>
    struct ComponentData {
        unsigned int size = 1;
        // the game engine support 1024 overall components
        std::array<ComponentType, 1024> data;
    };

//    struct ComponentInstance {
//        std::uint32_t index;
//    };
//
    template<typename ComponentType>
    class ComponentManager {
    public:
        //Add a new component to the entity
        ComponentInstance add(Entity entity, ComponentType& component);

        //Look up the component related to an entity
        ComponentType* lookup(Entity entity);

        //Destroy the component related to an entity
        void destroy(Entity entity);
    private:
        ComponentData<ComponentType> componentData;
        std::map<Entity, ComponentInstance> entityMap;
    };
}


#endif //NOOK_COMPONENTMANAGER_H
