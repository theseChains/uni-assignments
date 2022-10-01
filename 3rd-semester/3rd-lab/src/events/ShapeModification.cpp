#include "ShapeModification.h"

template <typename CircularShape>
void Modification::checkForCircularShapeModification(
        std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        Modification::enlargeCircles(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        Modification::reduceCircles(shapesToRender);
    }
}

template void Modification::checkForCircularShapeModification(std::array<std::unique_ptr<Circle>, 3>&);
template void Modification::checkForCircularShapeModification(std::array<std::unique_ptr<Ring>, 3>&);

void Modification::checkForRectangleModification(
        std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Modification::reduceHeightOfRectangles(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Modification::reduceWidthOfRectangles(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Modification::increaseHeightOfRectangles(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Modification::increaseWidthOfRectangles(rectanglesToRender);
    }
}

template <typename LineShape>
void Modification::checkForLineShapeModification(std::array<std::unique_ptr<LineShape>, 3>& linesShapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        Modification::rotateLinesClockwise(linesShapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        Modification::rotateLinesCounterClockwise(linesShapesToRender);
    }
}

template void Modification::checkForLineShapeModification(std::array<std::unique_ptr<Line>, 3>&);
template void Modification::checkForLineShapeModification(std::array<std::unique_ptr<Asterisk>, 3>&);

template <typename CircularShape>
void Modification::checkForCircularShapeArrayModification(
        VectorOfArrayOfCircularShapePtrs<CircularShape>& shapeArraysToRender)
{
    for (auto& shapeArray : shapeArraysToRender)
    {
        checkForCircularShapeModification(shapeArray);
    }
}

template void Modification::checkForCircularShapeArrayModification(VectorOfArrayOfCirclePtrs&);
template void Modification::checkForCircularShapeArrayModification(VectorOfArrayOfRingPtrs&);

void Modification::checkForRectangleArrayModification(
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    for (auto& rectangleArray : rectangleArraysToRender)
    {
        checkForRectangleModification(rectangleArray);
    }
}

template <typename LineShape>
void Modification::checkForLineShapeArrayModification(
        VectorOfArrayOfLineShapePtrs<LineShape>& lineArraysToRender)
{
    for (auto& lineArray : lineArraysToRender)
    {
        checkForLineShapeModification(lineArray);
    }
}

template void Modification::checkForLineShapeArrayModification(VectorOfArrayOfLinePtrs&);
template void Modification::checkForLineShapeArrayModification(VectorOfArrayOfAsteriskPtrs&);

// circle modification
template <typename CircularShape>
void Modification::enlargeCircles(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr)
        {
            shape->changeRadius(2.0f);
        }
    }
}

template <typename CircularShape>
void Modification::reduceCircles(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr)
        {
            shape->changeRadius(-2.0f);
        }
    }
}

// rectangle modification
void Modification::reduceHeightOfRectangles(
        std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    for (const auto& rectangle : rectanglesToRender)
    {
        if (rectangle.get() != nullptr)
        {
            rectangle->changeHeight(-2.0f);
        }
    }
}

void Modification::reduceWidthOfRectangles(
        std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    for (const auto& rectangle : rectanglesToRender)
    {
        if (rectangle.get() != nullptr)
        {
            rectangle->changeWidth(-2.0f);
        }
    }
}

void Modification::increaseHeightOfRectangles(
        std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    for (const auto& rectangle : rectanglesToRender)
    {
        if (rectangle.get() != nullptr)
        {
            rectangle->changeHeight(2.0f);
        }
    }
}

void Modification::increaseWidthOfRectangles(
        std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    for (const auto& rectangle : rectanglesToRender)
    {
        if (rectangle.get() != nullptr)
        {
            rectangle->changeWidth(2.0f);
        }
    }
}

// Line and Asterisk modification
template <typename LineShape>
void Modification::rotateLinesClockwise(std::array<std::unique_ptr<LineShape>, 3>& lineShapesToRender)
{
    for (const auto& lineShape : lineShapesToRender)
    {
        if (lineShape.get() != nullptr)
        {
            lineShape->rotate(2.0f);
        }
    }
}

template <typename LineShape>
void Modification::rotateLinesCounterClockwise(std::array<std::unique_ptr<LineShape>, 3>& lineShapesToRender)
{
    for (const auto& lineShape : lineShapesToRender)
    {
        if (lineShape.get() != nullptr)
        {
            lineShape->rotate(-2.0f);
        }
    }
}
