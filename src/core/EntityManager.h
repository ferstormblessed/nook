//
// Created by stormblessed on 7/17/24.
//

#pragma once

#ifndef NOOK_ENTITYMANAGER_H
#define NOOK_ENTITYMANAGER_H

#include <queue>
#include <array>
#include <cassert>
#include "Types.h"

namespace NOOK {

    class EntityManager {
    public:
        EntityManager() {
            for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
                m_availableEntities.push(entity);
            }
        }

        Entity createEntity() {
            assert(m_livingEntities < MAX_ENTITIES && "Too many entities in existence.\n");

            // Get ID from the front of the queue
            Entity newEntity = m_availableEntities.front();
            // Delete ID from the queue
            m_availableEntities.pop();
            ++m_livingEntities;
            return newEntity;
        }

        void destroyEntity(Entity entity) {
            assert(entity < MAK_COMPONENTS && "Entity out of range.\n");

            // Invalidate the destroyed Entity's Signature
            m_signatures[entity].reset();
            // Put destroyed Entity at the back of the queue
            m_availableEntities.push(entity);
            --m_livingEntities;

        }

        void setSignature(Entity entity, Signature signature) {
            assert(entity < MAX_ENTITIES && "Entity out of range.\n");

            m_signatures[entity] = signature;
        }

        Signature getSignature(Entity entity) {
            assert(entity < MAX_ENTITIES && "Entity out of range.\n");

            return m_signatures[entity];
        }

    private:
        std::queue<Entity> m_availableEntities{};
        std::array<Signature, MAX_ENTITIES> m_signatures{};
        uint32_t m_livingEntities{};
    };

} // NAMESPACE NOOK

#endif //NOOK_ENTITYMANAGER_H
