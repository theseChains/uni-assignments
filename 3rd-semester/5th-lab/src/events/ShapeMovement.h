#ifndef SHAPE_MOVEMENT_H
#define SHAPE_MOVEMENT_H

#include <array>
#include <memory>

#include "../aliases.h"
#include "../util.h"

#include "../shapes/Figure.h"
#include "../shapes/Circle.h"
#include "../shapes/Quadrangle.h"

namespace Movement
{
    void moveAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void moveCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);

    void QuadrangularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
            float verticalDirection = 0.0f, float horizontalDirection = 0.0f);
}

#endif
