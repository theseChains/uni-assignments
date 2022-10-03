#ifndef SHAPE_ARRAY_CREATION_H
#define SHAPE_ARRAY_CREATION_H

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"

#include "CircularShapeCreation.h"
#include "RectangleShapeCreation.h"
#include "QuadrangleShapeCreation.h"

namespace ArrayCreation
{
    // circle and ellipse arrays
    template <typename CircularShape>
    void checkForCircularShapeArrayCreation(VectorOfArrayOfCircularShapePtrs<CircularShape>& arraysToRender);

    template <typename CircularShape>
    void handleCircularShapeArrayCreation(VectorOfArrayOfCircularShapePtrs<CircularShape>& arraysToRender);

    // rectangle arrays
    void checkForRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

    void handleRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

    // quadrangle arrays
    void checkForQuadrangleArrayCreation(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender);

    void handleQuadrangleArrayCreation(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender);
}

#endif
