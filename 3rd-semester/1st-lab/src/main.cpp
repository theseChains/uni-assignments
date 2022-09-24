#include <SFML/Graphics.hpp>

#include "util.h"
#include "aliases.h"

#include "events/Events.h"
#include "events/ShapeCreation.h"
#include "events/ShapeMovement.h"
#include "events/ShapeModification.h"
#include "events/ShapeArrayCreation.h"

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

    // make a function to create an array of the desired shape with randomized shapes
    // make a function to delete the last array in the vector, if the vector is not empty (pop_back function)
    vector_of_circle_arrays circleArrays{};
    vector_of_rectangle_arrays rectangleArrays{};
    vector_of_line_arrays lineArrays{};

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

                handleCircleEvents(circlesToRender);
                handleRectangleEvents(rectanglesToRender);
                handleLineEvents(linesToRender);

                handleCircleArrayEvents(circleArrays);
            }
        }

        window.clear();

        renderer.renderShapes(circlesToRender);
        renderer.renderShapes(rectanglesToRender);
        renderer.renderShapes(linesToRender);

        renderer.renderShapeArrays(circleArrays);
        renderer.renderShapeArrays(rectangleArrays);
        renderer.renderShapeArrays(lineArrays);

        window.display();
    }

    return 0;
}
