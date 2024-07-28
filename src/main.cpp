#include "core/Coordinator.h"
#include <spdlog/spdlog.h>
#include "Systems/PhysicsSystem.h"

#define WIDTH 1920u
#define HEIGHT 1080u
#define FRAMES 30

int main()
{
    spdlog::info("ENTRY POINT: STARTING GAME");
    auto coordinator = std::make_shared<NOOK::Coordinator>();

}
