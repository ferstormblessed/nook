//
// Created by stormblessed on 10/27/24.
//

#include "NOOK/core/Coordinator.h"
#include "NOOK/Systems/Debug/DebugSystem.h"
#include "NOOK/components/Debug.h"
#include "NOOK/components/IntVariableDebug.h"
#include "NOOK/components/BoolVariableDebug.h"
#include "NOOK/components/FloatVariableDebug.h"
#include "NOOK/GUI/Screens.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::DebugSystem::init() {
    std::cout << "INFO: initializing DEBUG SYSTEM" << std::endl;
}

void NOOK::DebugSystem::update(const sf::Event* event) {
    for (auto& entity : m_entities) {
        auto& debug = gCoordinator.getComponent<NOOK::Debug>(entity);

        if ( sf::Event::KeyPressed == event->type &&
             sf::Keyboard::isKeyPressed(event->key.code)
             && debug.toggleDebug == event->key.code) {
            debug.debugOn = !debug.debugOn;
        }

        if (!debug.debugOn) return;


        if (debug.type == NOOK::INT) {
            auto& debugType = gCoordinator.getComponent<NOOK::IntVariableDebug>(entity);
            NOOK::IntVariableDebugGUI(debugType.name, debugType.value);
        } else if(debug.type == NOOK::FLOAT) {
            auto& debugType = gCoordinator.getComponent<NOOK::FloatVariableDebug>(entity);
            NOOK::FloatVariableDebugGUI(debugType.name, debugType.value);
        } else if (debug.type == NOOK::BOOL) {
            auto& debugType = gCoordinator.getComponent<NOOK::BoolVariableDebug>(entity);
            // NOOK::BoolVariableDebugGUI(debugType.name, debugType.value);
        }
    }
}
