#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics.hpp>

#include <iostream>

#include "util.h"
#include "aliases.h"

#include "events/Events.h"

#include "gui-events/GuiConfig.h"
#include "gui-events/GuiEvents.h"

#include "shapes/Figure.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Ellipse.h"
#include "shapes/Quadrangle.h"
#include "shapes/Rhombus.h"
#include "shapes/Trapezoid.h"

#include "render/Renderer.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study5" };
    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window))
    {
        std::cerr << "Failed to initialize ImGui\n";
        return 1;
    }

    configureGui();

    Renderer renderer{ window };

    std::array<std::unique_ptr<Figure>, 30> shapesToRender{};

    for (auto& shape : shapesToRender)
    {
        shape = std::make_unique<Trapezoid>(Creation::createFirstConstructorTrapezoid());
        shape->show();
    }

    sf::Clock deltaClock{};
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        startGuiLoop();

        ImGui::End();

        window.clear();

        renderer.renderShapeArray(shapesToRender);

        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
