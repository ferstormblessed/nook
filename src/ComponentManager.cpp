//
// Created by stormblessed on 7/17/24.
//

#include "ComponentManager.h"


template<typename ComponentType>
NOOK::ComponentInstance NOOK::ComponentManager<ComponentType>::add(Entity entity, ComponentType &component) {
    ComponentInstance newComponentInstance = { componentData.size };
    componentData.data[newComponentInstance] = component;
    entityMap[entity] = newComponentInstance;
    componentData.size++;
    return newComponentInstance;
}

template<typename ComponentType>
ComponentType* NOOK::ComponentManager<ComponentType>::lookup(Entity entity) {
    ComponentInstance componentInstance = entityMap[entity];
    return &componentData.data[componentInstance.index];
}

template<typename ComponentType>
void NOOK::ComponentManager<ComponentType>::destroy(Entity entity) {
    ComponentInstance componentInstance = entityMap[entity];
    ComponentInstance lastComponent = componentData.size - 1;
    componentData.data[componentInstance] = componentData.data[lastComponent];
    entityMap.erase(entity);
    componentData.size--;


}
