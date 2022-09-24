#ifndef SHAPE_ARRAY_CREATION_H
#define SHAPE_ARRAY_CREATION_H

#include <array>
#include <memory>
#include <vector>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

#include "ShapeCreation.h"

namespace ArrayCreation
{
    template <typename ShapeType>
    void checkForShapeArrayCreation(vector_of_shape_arrays<ShapeType>& arraysToRender);
}

void checkForRectangleArrayCreation(vector_of_rectangle_arrays& rectangleArraysToRender);

#endif
