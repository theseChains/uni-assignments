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

void Modification::checkForEllipseShapeModification(
        std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        Modification::rotateByNinetyDegrees(ellipsesToRender);
    }
}

void Modification::checkForRhombusShapeModification(
        std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Modification::reduceHeightOfRhombuses(rhombusesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Modification::reduceWidthOfRhombuses(rhombusesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Modification::increaseHeightOfRhombuses(rhombusesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Modification::increaseWidthOfRhombuses(rhombusesToRender);
    }
}

void Modification::checkForTrapezoidShapeModification(
        std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Modification::reduceHeightOfTrapezoids(trapezoidsToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Modification::reduceWidthOfTrapezoids(trapezoidsToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Modification::increaseHeightOfTrapezoids(trapezoidsToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Modification::increaseWidthOfTrapezoids(trapezoidsToRender);
    }
}

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

void Modification::checkForRectangleArrayModification(
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    for (auto& rectangleArray : rectangleArraysToRender)
    {
        checkForRectangleModification(rectangleArray);
    }
}

void Modification::checkForEllipseArrayModification(VectorOfArrayOfEllipsePtrs& ellipseArraysToRender)
{
    for (auto& ellipseArray : ellipseArraysToRender)
    {
        checkForEllipseShapeModification(ellipseArray);
    }
}

void Modification::checkForRhombusArrayModification(VectorOfArrayOfRhombusPtrs& rhombusArraysToRender)
{
    for (auto& rhombusArray : rhombusArraysToRender)
    {
        checkForRhombusShapeModification(rhombusArray);
    }
}

void Modification::checkForTrapezoidArrayModification(VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender)
{
    for (auto& trapezoidArray : trapezoidArraysToRender)
    {
        checkForTrapezoidShapeModification(trapezoidArray);
    }
}

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

// Ellipse modification
void Modification::rotateByNinetyDegrees(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender)
{
    for (const auto& ellipse : ellipsesToRender)
    {
        if (ellipse.get() != nullptr)
        {
            ellipse->rotateByNinetyDegrees();
        }
    }
}

// Rhombus modification
void Modification::reduceHeightOfRhombuses(
        std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender)
{
    for (const auto& rhombus : rhombusesToRender)
    {
        if (rhombus.get() != nullptr)
        {
            rhombus->changeSecondDiagonal(-2.0f);
        }
    }
}

void Modification::reduceWidthOfRhombuses(
        std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender)
{
    for (const auto& rhombus : rhombusesToRender)
    {
        if (rhombus.get() != nullptr)
        {
            rhombus->changeFirstDiagonal(-2.0f);
        }
    }
}

void Modification::increaseHeightOfRhombuses(
        std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender)
{
    for (const auto& rhombus : rhombusesToRender)
    {
        if (rhombus.get() != nullptr)
        {
            rhombus->changeSecondDiagonal(2.0f);
        }
    }
}

void Modification::increaseWidthOfRhombuses(
        std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender)
{
    for (const auto& rhombus : rhombusesToRender)
    {
        if (rhombus.get() != nullptr)
        {
            rhombus->changeFirstDiagonal(2.0f);
        }
    }
}

// Trapezoid modification
void Modification::reduceHeightOfTrapezoids(
        std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender)
{
    for (const auto& trapezoid : trapezoidsToRender)
    {
        if (trapezoid.get() != nullptr)
        {
            trapezoid->changeHeight(-2.0f);
        }
    }
}

void Modification::reduceWidthOfTrapezoids(
        std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender)
{
    for (const auto& trapezoid : trapezoidsToRender)
    {
        if (trapezoid.get() != nullptr)
        {
            trapezoid->changeTopBase(-2.0f);
            trapezoid->changeBottomBase(-2.0f);
        }
    }
}

void Modification::increaseHeightOfTrapezoids(
        std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender)
{
    for (const auto& trapezoid : trapezoidsToRender)
    {
        if (trapezoid.get() != nullptr)
        {
            trapezoid->changeHeight(2.0f);
        }
    }
}

void Modification::increaseWidthOfTrapezoids(
        std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender)
{
    for (const auto& trapezoid : trapezoidsToRender)
    {
        if (trapezoid.get() != nullptr)
        {
            trapezoid->changeTopBase(2.0f);
            trapezoid->changeBottomBase(2.0f);
        }
    }
}
