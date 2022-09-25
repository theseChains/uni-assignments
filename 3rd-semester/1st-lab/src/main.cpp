#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics.hpp>

#include <iostream>

#include "util.h"
#include "aliases.h"

#include "events/Events.h"

#include "gui-events/GuiEvents.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

#include "render/Renderer.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };
    window.setFramerateLimit(60);

    if (!ImGui::SFML::Init(window))
    {
        std::cerr << "Unable to initialize ImGui\n";
        return 1;
    }

    ImGui::GetStyle().ScaleAllSizes(1.2f);
    ImGui::GetIO().FontGlobalScale = 2.0f;
    ImGui::GetIO().ConfigWindowsResizeFromEdges = false;
    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;

    Renderer renderer{ window };

    std::array<std::unique_ptr<Circle>, 3> circlesToRender{};
    std::array<std::unique_ptr<Rectangle>, 3> rectanglesToRender{};
    std::array<std::unique_ptr<Line>, 3> linesToRender{};

    VectorOfArrayOfCirclePtrs circleArrays{};
    VectorOfArrayOfRectanglePtrs rectangleArrays{};
    VectorOfArrayOfLinePtrs lineArrays{};

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

                // todo: move rectangle creation in namespaces too
                handleCircleArrayEvents(circleArrays);
                handleRectangleArrayEvents(rectangleArrays);
                handleLineArrayEvents(lineArrays);
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin(mode::get().c_str());

        ImGui::SetWindowSize(ImVec2(util::guiWidth, util::windowHeight));
        ImGui::SetWindowPos(ImVec2(0, 0));

        if (ImGui::Button("Change mode (M)"))
        {
            mode::shift();
        }

        guiHandleCircleEvents(circlesToRender);
        guiHandleRectangleEvents(rectanglesToRender);
        guiHandleLineEvents(linesToRender);

        guiHandleCircleArrayEvents(circleArrays);
        guiHandleRectangleArrayEvents(rectangleArrays);
        guiHandleLineArrayEvents(lineArrays);

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
