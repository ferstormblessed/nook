#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <box2d/box2d.h>
#include "gui.h"
//#include "utilities.h"

#include "NookManager.h"

#define WIDTH 1920u
#define HEIGHT 1080u
#define FRAMES 30

int main()
{
    auto& nookManager = NookManager::getInstance();
    nookManager.startUp();
    nookManager.shutDown();
}

//// box2d initialization
//// gravity vector
//b2Vec2 gravity(0.0f, -10.0f);
//// create world
//b2World world(gravity);
//
//// create ground
//b2BodyDef groundBodyDef;
//groundBodyDef.position.Set(0.0f, -10.0f);
//
//b2Body* groundBody = world.CreateBody(&groundBodyDef);
//b2PolygonShape groundBox;
//groundBox.SetAsBox(50.0f, 10.0f);
//groundBody->CreateFixture(&groundBox, 0.0f);
//
////auto window = sf::RenderWindow{ {WIDTH, HEIGHT }, "nook" };
//auto window = sf::RenderWindow{sf::VideoMode(800, 600), "nook"};
//window.setFramerateLimit(FRAMES);
//
//if (!ImGui::SFML::Init(window)) {
//return -1;
//}
//
//sf::Clock clock;
//while (window.isOpen())
//{
//
//for (auto event = sf::Event{}; window.pollEvent(event);)
//{
//ImGui::SFML::ProcessEvent(window, event);
//
//if (event.type == sf::Event::Closed)
//{
//window.close();
//}
//}
//
//ImGui::SFML::Update(window, clock.restart());
//
//// gui function
//gui();
//
//window.clear();
//ImGui::SFML::Render(window);
//window.display();
//}
//
////print("fernando");
//ImGui::SFML::Shutdown();
