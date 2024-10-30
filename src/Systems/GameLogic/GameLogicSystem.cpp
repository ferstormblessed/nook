//
// Created by stormblessed on 10/6/24.
//

#include "NOOK/core/Coordinator.h"
#include "NOOK/Systems/GameLogic/GameLogicSystem.h"
#include "NOOK/components/Logic.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::GameLogicSystem::init() {
    std::cout << "INFO: initializing GAME LOGIC SYSTEM" << std::endl;
}

void NOOK::GameLogicSystem::update() {
    for (auto& entity : m_entities) {
        auto& logic = gCoordinator.getComponent<NOOK::Logic>(entity);
        logic.gameLogicFunction(entity);
    }
}
