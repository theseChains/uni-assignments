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
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study2" };
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
    std::array<std::unique_ptr<Ellipse>, 3> ellipsesToRender{};
    std::array<std::unique_ptr<Quadrangle>, 3> quadranglesToRender{};
    std::array<std::unique_ptr<Rhombus>, 3> rhombusesToRender{};
    std::array<std::unique_ptr<Trapezoid>, 3> trapezoidsToRender{};

    VectorOfArrayOfCirclePtrs circleArrays{};
    VectorOfArrayOfRectanglePtrs rectangleArrays{};
    VectorOfArrayOfEllipsePtrs ellipseArrays{};
    VectorOfArrayOfQuadranglePtrs quadrangleArrays{};
    VectorOfArrayOfRhombusPtrs rhombusArrays{};

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
                handleEllipseEvents(ellipsesToRender);
                handleQuadrangleEvents(quadranglesToRender);
                handleRhombusEvents(rhombusesToRender);
                handleTrapezoidEvents(trapezoidsToRender);

                handleCircleArrayEvents(circleArrays);
                handleRectangleArrayEvents(rectangleArrays);
                handleEllipseArrayEvents(ellipseArrays);
                handleQuadrangleArrayEvents(quadrangleArrays);
                handleRhombusArrayEvents(rhombusArrays);
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        startGuiLoop();

        guiHandleCircleArrayCreation(circleArrays);
        guiHandleRectangleArrayCreation(rectangleArrays);
        guiHandleEllipseArrayCreation(ellipseArrays);
        guiHandleQuadrangleArrayCreation(quadrangleArrays);
        guiHandleRhombusArrayCreation(rhombusArrays);

        guiHandleCircleEvents(circlesToRender, circleArrays);
        guiHandleRectangleEvents(rectanglesToRender, rectangleArrays);
        guiHandleEllipseEvents(ellipsesToRender, ellipseArrays);
        guiHandleQuadrangleEvents(quadranglesToRender, quadrangleArrays);
        guiHandleRhombusEvents(rhombusesToRender, rhombusArrays);

        ImGui::End();

        window.clear();

        renderer.renderCircleShapes(circlesToRender);
        renderer.renderQuadrangularShapes(rectanglesToRender);
        renderer.renderCircleShapes(ellipsesToRender);
        renderer.renderQuadrangularShapes(quadranglesToRender);
        renderer.renderQuadrangularShapes(rhombusesToRender);
        renderer.renderQuadrangularShapes(trapezoidsToRender);

        renderer.renderCircleShapeArrays(circleArrays);
        renderer.renderQuadrangularShapeArrays(rectangleArrays);
        renderer.renderCircleShapeArrays(ellipseArrays);
        renderer.renderQuadrangularShapeArrays(quadrangleArrays);
        renderer.renderQuadrangularShapeArrays(rhombusArrays);

        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
