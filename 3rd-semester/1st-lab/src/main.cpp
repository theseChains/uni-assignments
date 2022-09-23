#include <SFML/Graphics.hpp>

#include "util.h"

#include "events/Events.h"
#include "events/ShapeCreation.h"
#include "events/ShapeMovement.h"
#include "events/ShapeModification.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

#include "render/Renderer.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };
    window.setFramerateLimit(60);

    Renderer renderer{ window };

    std::array<std::unique_ptr<Circle>, 3> circlesToRender{};
    std::array<std::unique_ptr<Rectangle>, 3> rectanglesToRender{};
    std::array<std::unique_ptr<Line>, 3> linesToRender{};

    std::vector<std::array<Circle, 3>> circleArrays{};
    std::vector<std::array<Rectangle, 3>> rectangleArrays{};
    std::vector<std::array<Line, 3>> lineArrays{};

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
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
                    workspace::shift();
                }

                // todo: change function names to handleCircleEvents()
                handleCircleEvents(circlesToRender);
                handleRectangleEvents(rectanglesToRender);
                handleLineEvents(linesToRender);
            }
        }

        window.clear();

        renderer.renderShapes(circlesToRender);
        renderer.renderShapes(rectanglesToRender);
        renderer.renderShapes(linesToRender);

        window.display();
    }

    return 0;
}
