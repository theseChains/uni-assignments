#include "GuiShapeModification.h"

template <typename CircularShape>
void guiCheckForCircularShapeModification(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender,
       VectorOfArrayOfCircularShapePtrs<CircularShape>& shapeArraysToRender)
{
    if (ImGui::Button("Enlarge rings (O)"))
    {
        Modification::enlargeCircles(shapesToRender);

        for (auto& shapeArray : shapeArraysToRender)
        {
            Modification::enlargeCircles(shapeArray);
        }
    }
    if (ImGui::Button("Reduce rings (I)"))
    {
        Modification::reduceCircles(shapesToRender);

        for (auto& shapeArray : shapeArraysToRender)
        {
            Modification::reduceCircles(shapeArray);
        }
    }
}

template void guiCheckForCircularShapeModification(std::array<std::unique_ptr<Circle>, 3>&,
        VectorOfArrayOfCirclePtrs&);

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

void guiCheckForEllipseShapeModification(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender,
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
