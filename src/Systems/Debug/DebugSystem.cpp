//
// Created by stormblessed on 10/27/24.
//

#include "DebugSystem.h"
#include "spdlog/spdlog.h"
#include "../../core/Coordinator.h"
#include "../../components/Debug.h"
#include "../../components/FloatVariableDebug.h"
#include "../../components/IntVariableDebug.h"
#include "../../GUI/IntVariableDebugGUI.h"
#include "../../components/BoolVariableDebug.h"
#include "../../GUI/FloatVariableDebugGUI.h"
#include "../../components/RigidBody.h"

extern NOOK::Coordinator gCoordinator;

void NOOK::DebugSystem::init() {
    spdlog::info("initializing DEBUG SYSTEM");
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
