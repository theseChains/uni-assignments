#ifndef SHAPE_ARRAY_CREATION_H
#define SHAPE_ARRAY_CREATION_H

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"

#include "ShapeCreation.h"

namespace ArrayCreation
{
    // circle and ellipse arrays
    template <typename CircularShape>
    void checkForShapeArrayCreation(VectorOfArrayOfCircularShapePtrs<CircularShape>& arraysToRender);

    template <typename CircularShape>
    void handleShapeArrayCreation(VectorOfArrayOfCircularShapePtrs<CircularShape>& arraysToRender);

    // rectangle arrays
    void checkForRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

    void handleRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender); 
}

#endif
