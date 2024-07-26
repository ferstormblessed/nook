//
// Created by stormblessed on 7/17/24.
//

#pragma once

#ifndef NOOK_COMPONENTARRAY_H
#define NOOK_COMPONENTARRAY_H

#include <map>
#include <cassert>
#include "Types.h"

namespace NOOK {

    class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
    };

    template<typename T>
    class ComponentArray : public IComponentArray {
    public:
        void insertData(Entity entity, const T& component) {
            assert(m_entityToIndexMap.find(entity) == m_entityToIndexMap.end() && "Component added to the same Entity more than once\n");

            size_t newIndex = m_size;
            m_componentArray[newIndex] = component;
            m_entityToIndexMap[entity] = newIndex;
            m_indexToEntityMap[newIndex] = entity;
            ++m_size;
        }

        void removeData(Entity entity) {
            assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Removing non-existent component.\n");

            // state
            // oldE --> oldI
            // oldI --> oldE
            // lastE --> lastI
            // lastI --> lastE

            size_t indexOfRemovedEntity = m_entityToIndexMap[entity];
            size_t indexOfLastComponent = m_size - 1;
            m_componentArray[indexOfRemovedEntity] = m_componentArray[indexOfLastComponent];

            Entity entityOfLastComponent = m_indexToEntityMap[indexOfLastComponent];
            m_entityToIndexMap[entityOfLastComponent] = indexOfRemovedEntity;
            m_indexToEntityMap[indexOfRemovedEntity] = entityOfLastComponent;

            // state
            // oldE --> oldI     no change = entity                --> indexOfRemovedEntity   // want to delete
            // oldI --> lastE    change    = indexOfRemovedEntity  --> entityOfLastComponent  // preserve
            // lastE --> oldI    change    = entityOfLastComponent --> indexOfRemovedEntity   // preserve
            // lastI --> lastE   no change = indexOfLastComponent  --> entityOfLastComponent  // want to delete

            m_entityToIndexMap.erase(entity);
            m_indexToEntityMap.erase(indexOfLastComponent);

            --m_size;
        }

        T& getData(Entity entity){
            assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Retrieving non-existent component.\n");

            return m_componentArray[m_entityToIndexMap[entity]];
        }

        void entityDestroyed(Entity entity) override {
            if (m_entityToIndexMap.find(entity) != m_entityToIndexMap.end()) {
                // Remove entity's component
                removeData(entity);
            }
        }

    private:
        std::array<T, MAX_ENTITIES> m_componentArray{};
        std::map<Entity, size_t> m_entityToIndexMap{};
        std::map<size_t, Entity> m_indexToEntityMap{};
        size_t m_size{};
    };

} // NAMESPACE NOOK

#endif //NOOK_COMPONENTARRAY_H
