#include "Events.h"

void eventHandlerFunction(const sf::Event& event, 
        std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (event.type == event.KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            workspace::shift();
        }
                
        if (workspace::circles)
        {
            Creation::checkForShapeCreation(circlesToRender);
            checkForCircleModification(circlesToRender);
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
