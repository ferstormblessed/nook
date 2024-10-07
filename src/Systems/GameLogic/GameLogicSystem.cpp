//
// Created by stormblessed on 10/6/24.
//

#include "GameLogicSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"
#include "../../components/Logic.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::GameLogicSystem::init() {
    spdlog::info("initializing GAME LOGIC SYSTEM");
}

void NOOK::GameLogicSystem::update() {
    for (auto& entity : m_entities) {
        auto& logic = gCoordinator.getComponent<NOOK::Logic>(entity);
        logic.gameLogicFunction(entity);
    }
}
