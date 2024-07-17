//
// Created by stormblessed on 7/17/24.
//

#include "EntityMap.h"
#include "spdlog/spdlog.h"

Entity NOOK::EntityMap::getEntity(const ComponentInstance& component) {
    return instanceToEntity.at(component);
}

NOOK::ComponentInstance NOOK::EntityMap::getInstance(const Entity& entity) {
    return entityToInstance.at(entity);
}

void NOOK::EntityMap::add(const Entity& entity, const ComponentInstance& instance) {
    const auto& rt = entityToInstance.insert({entity, instance});
    if (!rt.second) {
        spdlog::warn("Entity = {0:d} already has ComponentInstance = {1:d}", entity.id, rt.first->second);
        spdlog::warn("Aborting EntityMap::add() function");
        return;
    }
    instanceToEntity.at(instance) = entity;
}

void NOOK::EntityMap::update(const Entity& entity, const ComponentInstance& instance) {
    entityToInstance.at(entity) = instance;
    instanceToEntity.at(instance) = entity;
}

void NOOK::EntityMap::remove(const Entity& entity) {
    entityToInstance.erase(entity);
}
