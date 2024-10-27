//
// Created by stormblessed on 10/27/24.
//

#include "PauseSystem.h"
#include "../../core/Coordinator.h"
#include "../../components/Pause.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::PauseSystem::init() {
    spdlog::info("initializing GAME LOGIC SYSTEM");
}

void NOOK::PauseSystem::update(sf::Event* event, GAME_STATE& gameState) {
    for (auto& entity : m_entities) {
        auto& pause = gCoordinator.getComponent<NOOK::Pause>(entity);

        if (gameState == NOOK::OVER_STATE) {
            return;
        }
        // pause with key
        if (sf::Keyboard::isKeyPressed(event->key.code) && pause.pauseKey == event->key.code) {
            pause.isPaused = !pause.isPaused;
            gameState = pause.isPaused ? NOOK::PAUSE_STATE : NOOK::PLAY_STATE;
        }

        if (gameState == NOOK::PAUSE_STATE) {
            pause.onPauseFunction(entity);
        }
    }
}
