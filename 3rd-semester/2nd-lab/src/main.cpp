#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics.hpp>

#include <iostream>

#include "util.h"
#include "aliases.h"

#include "events/Events.h"

#include "gui-events/GuiConfig.h"
#include "gui-events/GuiEvents.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"
#include "shapes/Ring.h"

#include "render/Renderer.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };
    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window))
    {
        std::cerr << "Failed to initialize ImGui\n";
        return 1;
    }

    configureGui();

    Renderer renderer{ window };

    std::array<std::unique_ptr<Circle>, 3> circlesToRender{};
    std::array<std::unique_ptr<Rectangle>, 3> rectanglesToRender{};
    std::array<std::unique_ptr<Line>, 3> linesToRender{};
    std::array<std::unique_ptr<Ring>, 3> ringsToRender{};

    VectorOfArrayOfCirclePtrs circleArrays{};
    VectorOfArrayOfRectanglePtrs rectangleArrays{};
    VectorOfArrayOfLinePtrs lineArrays{};
    VectorOfArrayOfRingPtrs ringArrays{};

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

            if (event.type == event.KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                {
                    mode::shift();
                }

                handleCircleEvents(circlesToRender);
                handleRectangleEvents(rectanglesToRender);
                handleLineEvents(linesToRender);

                handleCircleArrayEvents(circleArrays);
                handleRectangleArrayEvents(rectangleArrays);
                handleLineArrayEvents(lineArrays);
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        startGuiLoop();

        guiHandleCircleArrayCreation(circleArrays);
        guiHandleRectangleArrayCreation(rectangleArrays);
        guiHandleLineArrayCreation(lineArrays);

        guiHandleCircleEvents(circlesToRender, circleArrays);
        guiHandleRectangleEvents(rectanglesToRender, rectangleArrays);
        guiHandleLineEvents(linesToRender, lineArrays);

        ImGui::End();

        window.clear();

        renderer.renderShapes(circlesToRender);
        renderer.renderShapes(rectanglesToRender);
        renderer.renderShapes(linesToRender);

        renderer.renderShapeArrays(circleArrays);
        renderer.renderShapeArrays(rectangleArrays);
        renderer.renderShapeArrays(lineArrays);

        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
