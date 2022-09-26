#include "ShapeModification.h"

void checkForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        enlargeCircles(circlesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        reduceCircles(circlesToRender);
    }
}

void checkForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        reduceHeightOfRectangles(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        reduceWidthOfRectangles(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        increaseHeightOfRectangles(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        increaseWidthOfRectangles(rectanglesToRender);
    }
}

void checkForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        rotateLinesClockwise(linesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        rotateLinesCounterClockwise(linesToRender);
    }
}

void checkForCircleArrayModification(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    for (auto& circleArray : circleArraysToRender)
    {
        checkForCircleModification(circleArray);
    }
}

void checkForRectangleArrayModification(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    for (auto& rectangleArray : rectangleArraysToRender)
    {
        checkForRectangleModification(rectangleArray);
    }
}

void checkForLineArrayModification(VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    for (auto& lineArray : lineArraysToRender)
    {
        checkForLineModification(lineArray);
    }
}

// circle modification
void enlargeCircles(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    for (const auto& circle : circlesToRender)
    {
        if (circle.get() != nullptr)
        {
            circle->changeRadius(2.0f);
        }
    }
}

void reduceCircles(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    for (const auto& circle : circlesToRender)
    {
        if (circle.get() != nullptr)
        {
            circle->changeRadius(-2.0f);
        }
    }
}

// rectangle modification
void reduceHeightOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    for (const auto& rectangle : rectanglesToRender)
    {
        if (rectangle.get() != nullptr)
        {
            rectangle->changeHeight(-2.0f);
        }
    }
}

void reduceWidthOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    for (const auto& rectangle : rectanglesToRender)
    {
        if (rectangle.get() != nullptr)
        {
            rectangle->changeWidth(-2.0f);
        }
    }
}

void increaseHeightOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    for (const auto& rectangle : rectanglesToRender)
    {
        if (rectangle.get() != nullptr)
        {
            rectangle->changeHeight(2.0f);
        }
    }
}

void increaseWidthOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    for (const auto& rectangle : rectanglesToRender)
    {
        if (rectangle.get() != nullptr)
        {
            rectangle->changeWidth(2.0f);
        }
    }
}

// line modification
void rotateLinesClockwise(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    for (const auto& line : linesToRender)
    {
        if (line.get() != nullptr)
        {
            line->rotate(2.0f);
        }
    }
}

void rotateLinesCounterClockwise(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    for (const auto& line : linesToRender)
    {
        if (line.get() != nullptr)
        {
            line->rotate(-2.0f);
        }
    }
}
