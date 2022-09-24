#ifndef SHAPE_ARRAY_CREATION_H
#define SHAPE_ARRAY_CREATION_H

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

#include "ShapeCreation.h"

namespace ArrayCreation
{
    template <typename ShapeType>
    void checkForShapeArrayCreation(VectorOfArrayOfShapePtrs<ShapeType>& arraysToRender);
}

void checkForRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

#endif
