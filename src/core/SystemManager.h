//
// Created by stormblessed on 7/26/24.
//

#pragma once

#ifndef NOOK_SYSTEMMANAGER_H
#define NOOK_SYSTEMMANAGER_H

#include <map>
#include <memory>
#include <cassert>
#include "Types.h"
#include "System.h"

namespace NOOK {

    class SystemManager {
    public:
        template<typename T>
        std::shared_ptr<T> registerSystem() {
            const char* typeName = typeid(T).name();
            assert(m_systems.find(typeName) == m_systems.end() && "Registering system more than once.");

            // Create a pointer to the system and return it so it can be used externally
            auto system = std::make_shared<T>();
            m_systems.insert({typeName, system});
            return system;
        }

        template<typename T>
        void setSignature(Signature signature) {
            const char* typeName = typeid(T).name();
            assert(m_systems.find(typeName) != m_systems.end() && "System used before registered.");

            // Set the signature for this system
            m_signatures.insert({typeName, signature});
        }

        void entityDestroyed(Entity entity) {
            // Erase a destroyed entity from all system lists
            // m_entities is a set so no check needed
            for (auto const& pair : m_systems) {
                auto const& system = pair.second;
                system->m_entities.erase(entity);
            }
        }

        void entitySignatureChanged(Entity entity, Signature entitySignature) {
            // Notify each system that an entity's signature changed
            for (auto const& pair : m_systems) {
                auto const& type = pair.first;
                auto const& system = pair.second;
                auto const& systemSignature = m_signatures[type];

                // Entity signature matches system signature - insert into set
                if ((entitySignature & systemSignature) == systemSignature) {
                    system->m_entities.insert(entity);
                } else {
                    // Entity signature does not match system signature - erase from set
                    system->m_entities.erase(entity);
                }
            }
        }

    private:
        // TODO: thoroughly think if in this case using map, because memory is together, is better than unordered map since the latter is faster.
        // Map from system type string pointer to a signature
        std::map<const char*, Signature> m_signatures{};

        // Map from system type string pointer to a system pointer
        // TODO: fully investigate the implication of using a shared_ptr
        std::map<const char*, std::shared_ptr<System>> m_systems{};

    };

} // NAMESPACE NOOK

#endif //NOOK_SYSTEMMANAGER_H
