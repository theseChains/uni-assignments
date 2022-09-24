#ifndef SHAPE_MOVEMENT_H
#define SHAPE_MOVEMENT_H

#include <array>
#include <memory>

#include "../aliases.h"
#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

namespace Movement
{
    template <typename ShapeType>
    void checkForShapeMovement(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender);

    template <typename ShapeType>
    void checkForShapeArrayMovement(VectorOfArrayOfShapePtrs<ShapeType>& shapeArraysToRender);
}

#endif
