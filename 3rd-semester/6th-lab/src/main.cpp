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

#include "render/Renderer.h"

#include "containers/DynamicArray.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study6" };
    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window))
    {
        std::cerr << "Failed to initialize ImGui\n";
        return 1;
    }

    configureGui();

    DynamicArray<int> intVec(10);

    // i might have a const iterator here and i need a non-const one
    for (auto& element : intVec)
    {
        element = rnd::getNumber(1, 9);
    }

    for (const auto& element : intVec)
    {
        std::cout << element << ' ';
    }

    Renderer renderer{ window };

    std::array<std::unique_ptr<Figure>, 30> shapesToRender{};

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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            {
                mode::shift();
            }

            if (event.type == event.KeyPressed)
            {
                handleShapeArrayEvents(shapesToRender);
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        startGuiLoop();

        if (ImGui::Button("Change mode (M)"))
        {
            mode::shift();
        }

        guiHandleShapeArrayEvents(shapesToRender);

        ImGui::End();

        window.clear();

        renderer.renderShapeArray(shapesToRender);

        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
