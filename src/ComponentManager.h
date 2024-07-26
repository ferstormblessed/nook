//
// Created by stormblessed on 7/26/24.
//

#pragma once

#ifndef NOOK_COMPONENTMANAGER_H
#define NOOK_COMPONENTMANAGER_H

#include <map>
#include <memory>
#include "Types.h"
#include "ComponentArray.h"

namespace NOOK {
    class ComponentManager {
    public:
        template<typename T>
        void registerComponent() {
            const char* typeName = typeid(T).name();
            assert(m_componentTypes.find(typeName) == m_componentTypes.end() && "Registering component type more than once.");

            // Add this component type to the component type map
            m_componentTypes.insert({typeName, m_nextComponentType});

            // Create a ComponentArray pointer and add it to the component arrays map
            m_componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

            // Increment the value so that the next component registered will be different
            ++m_nextComponentType;
        }

        template<typename T>
        ComponentType getComponentType() {
            const char* typeName = typeid(T).name();
            assert(m_componentTypes.find(typeName) != m_componentTypes.end() && "Component not registered before use.");

            // Return this component's type - used for creating signatures
            return m_componentTypes[typeName];
        }

        template<typename T>
        void addComponent(Entity entity, T component) {
            // Add a component to the array for an entity
            getComponentArray<T>()->insertData(entity, component);
        }

        template<typename T>
        void removeComponent(Entity entity) {
            // Remove a component from the array for an entity
            getComponentArray<T>()->removeData(entity);
        }

        template<typename T>
        T& getComponent(Entity entity) {
            // Get a reference to a component from the array for an entity
            return getComponentArray<T>()->getData(entity);
        }

        void entityDestroyed(Entity entity) {
            // Notify each component array that an entity has been destroyed
            // If it has a component for that entity, it will remove it
            for (auto const& pair : m_componentArrays) {
                auto const& component = pair.second;
                component->entityDestroyed(entity);
            }
        }

    private:
        // Map from type string pointer to a component type
        std::map<const char*, NOOK::ComponentType> m_componentTypes{};

        // Map from type string pointer to a component array
        // TODO: fully investigate the implication of using a shared_ptr
        std::map<const char*, std::shared_ptr<IComponentArray>> m_componentArrays{};

        // The component type to be assigned to the next registered component - starting at 0
        ComponentType m_nextComponentType{};

        // Convenience function to get the statically casted pointer to the ComponentArray of type T.
        template<typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray()
        {
            const char* typeName = typeid(T).name();
            assert(m_componentTypes.find(typeName) != m_componentTypes.end() && "Component not registered before use.");

            // TODO: investigate the static pointer cast complete functionality
            return std::static_pointer_cast<ComponentArray<T>>(m_componentArrays[typeName]);
        }
    };

} // NAMESPACE NOOK

#endif //NOOK_COMPONENTMANAGER_H
