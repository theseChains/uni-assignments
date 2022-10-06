#ifndef SHAPE_MOVEMENT_H
#define SHAPE_MOVEMENT_H

#include <array>
#include <memory>

#include "../aliases.h"
#include "../util.h"

#include "../shapes/Figure.h"
#include "../shapes/Circle.h"
#include "../shapes/Quadrangle.h"

#include "../containers/DynamicArray.h"

namespace Movement
{
    void checkForShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void checkForCircularShapeMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void checkForQuadrangularShapeMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void moveAllShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void moveCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void moveQuadrangularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);
}

#endif
