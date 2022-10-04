#ifndef TRAPEZOID_SHAPE_CREATION_H
#define TRAPEZOID_SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Trapezoid.h"

#include "ShapeCreationAuxiliary.h"

namespace Creation
{
    void checkForTrapezoidShapeCreation(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender);

    void createAndShowDefaultTrapezoid(std::unique_ptr<Trapezoid>& newTrapezoidPtr);
    Trapezoid createFirstConstructorTrapezoid();
    Trapezoid createSecondConstructorTrapezoid();

    void handleDefaultTrapezoidShapeCreation(std::unique_ptr<Trapezoid>& trapezoidPtr);
    void handleFirstConstructorTrapezoidCreation(std::unique_ptr<Trapezoid>& trapezoidPtr);
    void handleSecondConstructorTrapezoidCreation(std::unique_ptr<Trapezoid>& trapezoidPtr);
}

#endif
