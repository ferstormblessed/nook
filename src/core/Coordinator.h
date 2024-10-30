//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_COORDINATOR_H
#define NOOK_COORDINATOR_H

#include <memory>
#include "ComponentManager.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include <iostream>

namespace NOOK {

    class Coordinator {
    public:
        void init() {
            std::cout << "INFO: Initializing COORDINATOR" << std::endl;
            // Create pointers to each manager
            m_componentManager = std::make_unique<ComponentManager>();
            m_entityManager = std::make_unique<EntityManager>();
            m_systemManager = std::make_unique<SystemManager>();
        }

        // Entity methods
        Entity createEntity() {
            return m_entityManager->createEntity();
        }

        void destroyEntity(Entity entity) {
            m_entityManager->destroyEntity(entity);
            m_componentManager->entityDestroyed(entity);
            m_systemManager->entityDestroyed(entity);
        }

        // Component methods
        template<typename T>
        void registerComponent() {
            m_componentManager->registerComponent<T>();
        }

        template<typename T>
        void addComponent(Entity entity, T component) {
            m_componentManager->addComponent<T>(entity, component);

            auto signature = m_entityManager->getSignature(entity);
            signature.set(m_componentManager->getComponentType<T>(), true);
            m_entityManager->setSignature(entity, signature);

            m_systemManager->entitySignatureChanged(entity, signature);
        }

        template<typename T>
        void removeComponent(Entity entity) {
            m_componentManager->removeComponent<T>(entity);

            auto signature = m_entityManager->getSignature(entity);
            signature.set(m_componentManager->getComponentType<T>(), false);
            m_entityManager->setSignature(entity, signature);

            m_systemManager->entitySignatureChanged(entity, signature);
        }

        template<typename T>
        T& getComponent(Entity entity) {
            return m_componentManager->getComponent<T>(entity);
        }

        template<typename T>
        ComponentType getComponentType() {
            return m_componentManager->getComponentType<T>();
        }

        // System methods
        template<typename T>
        std::shared_ptr<T> registerSystem() {
            return m_systemManager->registerSystem<T>();
        }

        template<typename T>
        void setSystemSignature(Signature signature) {
            m_systemManager->setSignature<T>(signature);
        }

    private:
        std::unique_ptr<ComponentManager> m_componentManager{};
        std::unique_ptr<EntityManager> m_entityManager{};
        std::unique_ptr<SystemManager> m_systemManager{};
    };

} // NAMESPACE NOOK

#endif //NOOK_COORDINATOR_H
