#include "GuiShapeModification.h"

void guiCheckForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
       VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (ImGui::Button("Enlarge circles (O)"))
    {
        Modification::enlargeCircles(circlesToRender);

        for (auto& circleArray : circleArraysToRender)
        {
            Modification::enlargeCircles(circleArray);
        }
    }
    if (ImGui::Button("Reduce circles (I)"))
    {
        Modification::reduceCircles(circlesToRender);

        for (auto& circleArray : circleArraysToRender)
        {
            Modification::reduceCircles(circleArray);
        }
    }
}

void guiCheckForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (ImGui::Button("Reduce height of\nrectangles (Up)"))
    {
        Modification::reduceHeightOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            Modification::reduceHeightOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Reduce width of\nrectangles (Left)"))
    {
        Modification::reduceWidthOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            Modification::reduceWidthOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Increase height of\nrectangles (Down)"))
    {
        Modification::increaseHeightOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            Modification::increaseHeightOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Increase width of\nrectangles (Right)"))
    {
        Modification::increaseWidthOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            Modification::increaseWidthOfRectangles(rectangleArray);
        }
    }
}

void guiCheckForEllipseModification(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender,
        VectorOfArrayOfEllipsePtrs& ellipseArraysToRender)
{
    if (ImGui::Button("Rotate by 90 degrees (R)"))
    {
        Modification::rotateByNinetyDegrees(ellipsesToRender);

        for (auto& ellipseArray : ellipseArraysToRender)
        {
            Modification::rotateByNinetyDegrees(ellipseArray);
        }
    }
}

void guiCheckForRhombusModification(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender,
        VectorOfArrayOfRhombusPtrs& rhombusArraysToRender)
{
    if (ImGui::Button("Reduce height of\nrhombuses (Up)"))
    {
        Modification::reduceHeightOfRhombuses(rhombusesToRender);

        for (auto& rhombusArray : rhombusArraysToRender)
        {
            Modification::reduceHeightOfRhombuses(rhombusArray);
        }
    }
    if (ImGui::Button("Reduce width of\nrhombuses (Left)"))
    {
        Modification::reduceWidthOfRhombuses(rhombusesToRender);

        for (auto& rhombusArray : rhombusArraysToRender)
        {
            Modification::reduceWidthOfRhombuses(rhombusArray);
        }
    }
    if (ImGui::Button("Increase height of\nrhombuses (Down)"))
    {
        Modification::increaseHeightOfRhombuses(rhombusesToRender);

        for (auto& rhombusArray : rhombusArraysToRender)
        {
            Modification::increaseHeightOfRhombuses(rhombusArray);
        }
    }
    if (ImGui::Button("Increase width of\nrhombuses (Right)"))
    {
        Modification::increaseWidthOfRhombuses(rhombusesToRender);

        for (auto& rhombusArray : rhombusArraysToRender)
        {
            Modification::increaseWidthOfRhombuses(rhombusArray);
        }
    }
}

void guiCheckForTrapezoidModification(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender,
        VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender)
{
    if (ImGui::Button("Reduce height of\ntrapezoids (Up)"))
    {
        Modification::reduceHeightOfTrapezoids(trapezoidsToRender);

        for (auto& trapezoidArray : trapezoidArraysToRender)
        {
            Modification::reduceHeightOfTrapezoids(trapezoidArray);
        }
    }
    if (ImGui::Button("Reduce width of\ntrapezoids (Left)"))
    {
        Modification::reduceWidthOfTrapezoids(trapezoidsToRender);

        for (auto& trapezoidArray : trapezoidArraysToRender)
        {
            Modification::reduceWidthOfTrapezoids(trapezoidArray);
        }
    }
    if (ImGui::Button("Increase height of\ntrapezoids (Down)"))
    {
        Modification::increaseHeightOfTrapezoids(trapezoidsToRender);

        for (auto& trapezoidArray : trapezoidArraysToRender)
        {
            Modification::increaseHeightOfTrapezoids(trapezoidArray);
        }
    }
    if (ImGui::Button("Increase width of\ntrapezoids (Right)"))
    {
        Modification::increaseWidthOfTrapezoids(trapezoidsToRender);

        for (auto& trapezoidArray : trapezoidArraysToRender)
        {
            Modification::increaseWidthOfTrapezoids(trapezoidArray);
        }
    }
}
