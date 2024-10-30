//
// Created by stormblessed on 10/27/24.
//

#include "GameOverSystem.h"
#include "../../core/Coordinator.h"
#include "../../components/GameOver.h"
#include <iostream>

extern NOOK::Coordinator gCoordinator;

void NOOK::GameOverSystem::init() {
    std::cout << "INFO: initializing GAME OVER SYSTEM" << std::endl;
}

void NOOK::GameOverSystem::update(NOOK::GAME_STATE &gameState) {
    for (auto& entity : m_entities) {
        auto& gameOver = gCoordinator.getComponent<NOOK::GameOver>(entity);

        if (gameState == NOOK::PAUSE_STATE) {
            return;
        }

        if (gameOver.isOver) {
            gameState = NOOK::OVER_STATE;
            gameOver.gameOverFunction(entity);
        }

        if (gameOver.playAgain) {
            gameState = NOOK::PLAY_STATE;
            gameOver.playAgainFunction(entity);
        }
    }
}
