#include "Events.h"

// unique shape modifications
void checkForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        for (const auto& circle : circlesToRender)
        {
            if (circle.get() != nullptr)
            {
                circle->changeRadius(2.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        for (const auto& circle : circlesToRender)
        {
            if (circle.get() != nullptr)
            {
                circle->changeRadius(-2.0f);
            }
        }
    }
}

void checkForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        for (const auto& rectangle : rectanglesToRender)
        {
            if (rectangle.get() != nullptr)
            {
                rectangle->changeHeight(-2.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        for (const auto& rectangle : rectanglesToRender)
        {
            if (rectangle.get() != nullptr)
            {
                rectangle->changeWidth(-2.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        for (const auto& rectangle : rectanglesToRender)
        {
            if (rectangle.get() != nullptr)
            {
                rectangle->changeHeight(2.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        for (const auto& rectangle : rectanglesToRender)
        {
            if (rectangle.get() != nullptr)
            {
                rectangle->changeWidth(2.0f);
            }
        }
    }
}

void checkForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        for (const auto& line : linesToRender)
        {
            if (line.get() != nullptr)
            {
                line->rotate(2.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        for (const auto& line : linesToRender)
        {
            if (line.get() != nullptr)
            {
                line->rotate(-2.0f);
            }
        }
    }
}
