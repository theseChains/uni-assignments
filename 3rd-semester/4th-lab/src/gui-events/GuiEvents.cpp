#include "GuiEvents.h"

void guiHandleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        GuiCreation::checkForCircularShapeCreation(circlesToRender);
        guiCheckForCircleModification(circlesToRender, circleArraysToRender);
        guiCheckForShapeMovement(circlesToRender, circleArraysToRender);
    }
}

void guiHandleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {
        GuiCreation::checkForParallelogramCreation(rectanglesToRender);
        guiCheckForRectangleModification(rectanglesToRender, rectangleArraysToRender);
        guiCheckForShapeMovement(rectanglesToRender, rectangleArraysToRender);
    }
}

void guiHandleEllipseEvents(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender,
        VectorOfArrayOfEllipsePtrs& ellipseArraysToRender)
{
    if (mode::ellipses)
    {
        GuiCreation::checkForCircularShapeCreation(ellipsesToRender);
        guiCheckForEllipseModification(ellipsesToRender, ellipseArraysToRender);
        guiCheckForShapeMovement(ellipsesToRender, ellipseArraysToRender);
    }
}

void guiHandleQuadrangleEvents(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender,
        VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    if (mode::quadrangles)
    {
        GuiCreation::checkForQuadrangleCreation(quadranglesToRender);
        guiCheckForShapeMovement(quadranglesToRender, quadrangleArraysToRender);
    }
}

void guiHandleRhombusEvents(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender,
        VectorOfArrayOfRhombusPtrs& rhombusArraysToRender)
{
    if (mode::rhombuses)
    {
        GuiCreation::checkForParallelogramCreation(rhombusesToRender);
        guiCheckForRhombusModification(rhombusesToRender, rhombusArraysToRender);
        guiCheckForShapeMovement(rhombusesToRender, rhombusArraysToRender);
    }
}

void guiHandleTrapezoidEvents(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender,
        VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender)
{
    if (mode::trapezoids)
    {
        GuiCreation::checkForTrapezoidCreation(trapezoidsToRender);
        guiCheckForTrapezoidModification(trapezoidsToRender, trapezoidArraysToRender);
        guiCheckForShapeMovement(trapezoidsToRender, trapezoidArraysToRender);
    }
}

// array creation
void guiHandleCircleArrayCreation(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        GuiArrayCreation::checkForCircularShapeArrayCreation(circleArraysToRender);
    }
}

void guiHandleRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {
        GuiArrayCreation::checkForParallelogramArrayCreation(rectangleArraysToRender);
    }
}

void guiHandleEllipseArrayCreation(VectorOfArrayOfEllipsePtrs& ellipseArraysToRender)
{
    if (mode::ellipses)
    {
        GuiArrayCreation::checkForCircularShapeArrayCreation(ellipseArraysToRender);
    }
}

void guiHandleQuadrangleArrayCreation(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    if (mode::quadrangles)
    {
        GuiArrayCreation::checkForQuadrangleArrayCreation(quadrangleArraysToRender);
    }
}

void guiHandleRhombusArrayCreation(VectorOfArrayOfRhombusPtrs& rhombusArraysToRender)
{
    if (mode::rhombuses)
    {
        GuiArrayCreation::checkForParallelogramArrayCreation(rhombusArraysToRender);
    }
}

void guiHandleTrapezoidArrayCreation(VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender)
{
    if (mode::trapezoids)
    {
        GuiArrayCreation::checkForTrapezoidArrayCreation(trapezoidArraysToRender);
    }
}
