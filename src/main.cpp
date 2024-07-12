#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include "gui.h"
#include "utilities.h"

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "nook" };
    window.setFramerateLimit(144);

    if (!ImGui::SFML::Init(window)) {
        return -1;
    }

    sf::Clock clock;
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, clock.restart());

        gui();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    print("fernando");
    ImGui::SFML::Shutdown();
}
