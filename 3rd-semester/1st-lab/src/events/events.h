#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include <memory>
#include <ranges>

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

void checkForCircleShapeCreation(std::vector<std::unique_ptr<Circle>>& circlesToRender);
void checkForRectangleShapeCreation(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender);
void checkForLineShapeCreation(std::vector<std::unique_ptr<Line>>& linesToRender);

void checkForCircleModification(std::vector<std::unique_ptr<Circle>>& circlesToRender);
void checkForRectangleModification(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender);
void checkForLineModification(std::vector<std::unique_ptr<Line>>& linesToRender);

template <typename ShapeType>
void checkForShapeMovement(std::vector<std::unique_ptr<ShapeType>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        for (const auto& shape : shapesToRender)
        {
            shape->moveTo(0.0f, -2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        for (const auto& shape : shapesToRender)
        {
            shape->moveTo(-2.0f, 0.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        for (const auto& shape : shapesToRender)
        {
            shape->moveTo(0.0f, 2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        for (const auto& shape : shapesToRender)
        {
            shape->moveTo(2.0f, 0.0f);
        }
    }
}

#endif
