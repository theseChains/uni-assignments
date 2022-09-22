#include <SFML/Graphics.hpp>

#include "events/events.h"
#include "util.h"

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ util::windowWidth, util::windowHeight }, "study" };
    window.setFramerateLimit(60);

    std::array<std::unique_ptr<Circle>, 3> circlesToRender{};
    std::array<std::unique_ptr<Rectangle>, 3> rectanglesToRender{};
    std::array<std::unique_ptr<Line>, 3> linesToRender{};

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
           
            if (event.type == event.KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                {
                    workspace::shift();
                }
                
                if (workspace::circles)
                {
                    Creation::checkForShapeCreation(circlesToRender);
                    //checkForCircleModification(circlesToRender);
                    Movement::checkForShapeMovement(circlesToRender);
                }
                else if (workspace::rectangles)
                {
                    checkForRectangleShapeCreation(rectanglesToRender);
                    checkForRectangleModification(rectanglesToRender);
                    Movement::checkForShapeMovement(rectanglesToRender);
                }
                else if (workspace::lines)
                {
                    Creation::checkForShapeCreation(linesToRender);
                    checkForLineModification(linesToRender);
                    Movement::checkForShapeMovement(linesToRender);
                }
            }
        }

        window.clear();

        for (const auto& circle : circlesToRender)
        {
            if (circle.get() != nullptr && circle.get()->isShown())
            {
                window.draw(circle.get()->getSprite());
            }
        }

        for (const auto& rectangle : rectanglesToRender)
        {
            if (rectangle.get() != nullptr && rectangle.get()->isShown())
            {
                window.draw(rectangle.get()->getSprite());
            }
        }

        for (const auto& line : linesToRender)
        {
            if (line.get() != nullptr && line.get()->isShown())
            {
                window.draw(line.get()->getSprite());
            }
        }

        window.display();
    }

    return 0;
}
