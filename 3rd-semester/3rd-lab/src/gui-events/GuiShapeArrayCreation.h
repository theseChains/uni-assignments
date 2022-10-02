#ifndef GUI_SHAPE_ARRAY_CREATION_H
#define GUI_SHAPE_ARRAY_CREATION_H

#include <imgui.h>
#include <imgui-SFML.h>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"

#include "../events/ShapeArrayCreation.h"

namespace GuiArrayCreation
{
    template <typename ShapeType>
    void checkForShapeArrayCreation(VectorOfArrayOfShapePtrs<ShapeType>& arraysToRender);

    void checkForRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
}

#endif
