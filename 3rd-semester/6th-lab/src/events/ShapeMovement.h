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
#include "../containers/DynamicList.h"

namespace Movement
{
    void checkForShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void checkForCircularShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void checkForQuadrangularShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void checkForShapeListMovement(DynamicList<std::unique_ptr<Figure>>& shapesToRender);

    void checkForCircularShapeListMovement(DynamicList<std::unique_ptr<Figure>>& shapesToRender);

    void checkForQuadrangularShapeListMovement(DynamicList<std::unique_ptr<Figure>>& shapesToRender);

    void moveAllArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void moveCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void moveQuadrangularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void moveAllListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void moveCircularListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void moveQuadrangularListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);
}

#endif
