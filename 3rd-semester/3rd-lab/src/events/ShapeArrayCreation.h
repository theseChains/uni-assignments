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
    // line, circle and ring arrays
    template <typename ShapeType>
    void checkForShapeArrayCreation(VectorOfArrayOfShapePtrs<ShapeType>& arraysToRender);

    template <typename ShapeType>
    void handleShapeArrayCreation(VectorOfArrayOfShapePtrs<ShapeType>& arraysToRender);

    // rectangle arrays
    void checkForRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

    void handleRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender); 
}

#endif
