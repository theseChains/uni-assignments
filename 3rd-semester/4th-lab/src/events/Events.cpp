#include "Events.h"

void handleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    if (mode::circles)
    {
        Creation::checkForCircularShapeCreation(circlesToRender);
        Modification::checkForCircularShapeModification(circlesToRender);
        Movement::checkForShapeMovement(circlesToRender);
    }
}

void handleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (mode::rectangles)
    {
        Creation::checkForParallelogrammaticShapeCreation(rectanglesToRender);
        Modification::checkForRectangleModification(rectanglesToRender);
        Movement::checkForShapeMovement(rectanglesToRender);
    }
}

void handleEllipseEvents(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender)
{
    if (mode::ellipses)
    {
        Creation::checkForCircularShapeCreation(ellipsesToRender);
        Modification::checkForEllipseShapeModification(ellipsesToRender);
        Movement::checkForShapeMovement(ellipsesToRender);
    }
}

void handleQuadrangleEvents(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender)
{
    if (mode::quadrangles)
    {
        Creation::checkForQuadrangleShapeCreation(quadranglesToRender);
        Movement::checkForShapeMovement(quadranglesToRender);
    }
}

void handleRhombusEvents(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender)
{
    if (mode::rhombuses)
    {
        Creation::checkForParallelogrammaticShapeCreation(rhombusesToRender);
        Modification::checkForRhombusShapeModification(rhombusesToRender);
        Movement::checkForShapeMovement(rhombusesToRender);
    }
}

void handleTrapezoidEvents(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender)
{
    if (mode::trapezoids)
    {
        Creation::checkForTrapezoidShapeCreation(trapezoidsToRender);
        Modification::checkForTrapezoidShapeModification(trapezoidsToRender);
        Movement::checkForShapeMovement(trapezoidsToRender);
    }
}

// arrays of shapes
void handleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        ArrayCreation::checkForCircularShapeArrayCreation(circleArraysToRender);
        Modification::checkForCircularShapeArrayModification(circleArraysToRender);
        Movement::checkForShapeArrayMovement(circleArraysToRender);
    }
}

void handleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {
        ArrayCreation::checkForParallelogramArrayCreation(rectangleArraysToRender);
        Modification::checkForRectangleArrayModification(rectangleArraysToRender);
        Movement::checkForShapeArrayMovement(rectangleArraysToRender);
    }
}

void handleEllipseArrayEvents(VectorOfArrayOfEllipsePtrs& ellipseArraysToRender)
{
    if (mode::ellipses)
    {
        ArrayCreation::checkForCircularShapeArrayCreation(ellipseArraysToRender);
        Modification::checkForEllipseArrayModification(ellipseArraysToRender);
        Movement::checkForShapeArrayMovement(ellipseArraysToRender);
    }
}

void handleQuadrangleArrayEvents(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    if (mode::quadrangles)
    {
        ArrayCreation::checkForQuadrangleArrayCreation(quadrangleArraysToRender);
        Movement::checkForShapeArrayMovement(quadrangleArraysToRender);
    }
}

void handleRhombusArrayEvents(VectorOfArrayOfRhombusPtrs& rhombusArraysToRender)
{
    if (mode::rhombuses)
    {
        ArrayCreation::checkForParallelogramArrayCreation(rhombusArraysToRender);
        Modification::checkForRhombusArrayModification(rhombusArraysToRender);
        Movement::checkForShapeArrayMovement(rhombusArraysToRender);
    }
}

void handleTrapezoidArrayEvents(VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender)
{
    if (mode::trapezoids)
    {
        ArrayCreation::checkForTrapezoidArrayCreation(trapezoidArraysToRender);
        Modification::checkForTrapezoidArrayModification(trapezoidArraysToRender);
        Movement::checkForShapeArrayMovement(trapezoidArraysToRender);
    }
}
