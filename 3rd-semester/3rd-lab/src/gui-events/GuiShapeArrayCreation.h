#ifndef GUI_SHAPE_ARRAY_CREATION_H
#define GUI_SHAPE_ARRAY_CREATION_H

#include <imgui.h>
#include <imgui-SFML.h>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"

#include "../events/ShapeArrayCreation.h"

namespace GuiArrayCreation
{
    template <typename CircularShape>
    void checkForCircularShapeArrayCreation(VectorOfArrayOfShapePtrs<CircularShape>& arraysToRender);

    void checkForRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

    void checkForQuadrangleArrayCreation(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender);
}

#endif
