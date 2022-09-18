#include <SFML/Graphics.hpp>

#include "events/events.h"
#include "util.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };

    std::vector<std::unique_ptr<Circle>> circlesToRender{};
    std::vector<std::unique_ptr<Rectangle>> rectanglesToRender{};
    std::vector<std::unique_ptr<Line>> linesToRender{};

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
           
            // todo: add the event handler function (maybe even a class?)
            if (event.type == event.KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                {
                    workspace::shift();
                }
                
                // todo: add changeProperty event handlers
                if (workspace::circles)
                {
                    checkForCircleShapeCreation(circlesToRender);
                    checkForCircleModification(circlesToRender);
                    checkForShapeMovement(circlesToRender);
                }
                else if (workspace::rectangles)
                {
                    checkForRectangleShapeCreation(rectanglesToRender);
                    checkForRectangleModification(rectanglesToRender);
                    checkForShapeMovement(rectanglesToRender);
                }
                else if (workspace::lines)
                {
                    checkForLineShapeCreation(linesToRender);
                    checkForLineModification(linesToRender);
                    checkForShapeMovement(linesToRender);
                }
            }
        }

        window.clear();

        for (const auto& circle : circlesToRender)
        {
           window.draw(circle.get()->getSprite());
        }

        for (const auto& rectangle : rectanglesToRender)
        {
            window.draw(rectangle.get()->getSprite());
        }

        for (const auto& line : linesToRender)
        {
            window.draw(line.get()->getSprite());
        }

        window.display();
    }

    return 0;
}
