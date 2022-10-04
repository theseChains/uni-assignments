#ifndef PARALLELOGRAMMATIC_SHAPE_CREATION_H
#define PARALLELOGRAMMATIC_SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Rectangle.h"
#include "../shapes/Rhombus.h"

#include "ShapeCreationAuxiliary.h"

namespace Creation
{
    // for Rhombus and Rectangle classes
    template <typename ParallelogrammaticShape>
    void checkForParallelogrammaticShapeCreation(
            std::array<std::unique_ptr<ParallelogrammaticShape>, 3>& shapesToRender);

    template <typename ParallelogrammaticShape>
    void createAndShowDefaultParallelogrammaticShape(
            std::unique_ptr<ParallelogrammaticShape>& newShapePtr);

    template <typename ParallelogrammaticShape>
    ParallelogrammaticShape createFirstConstructorParallelogrammaticShape();

    template <typename ParallelogrammaticShape>
    ParallelogrammaticShape createSecondConstructorParallelogrammaticShape();

    template <typename ParallelogrammaticShape>
    void handleDefaultParallelogramCreation(std::unique_ptr<ParallelogrammaticShape>& shapePtr);

    template <typename ParallelogrammaticShape>
    void handleFirstConstructorParallelogramCreation(
            std::unique_ptr<ParallelogrammaticShape>& shapePtr);

    template <typename ParallelogrammaticShape>
    void handleSecondConstructorParallelogramCreation(
            std::unique_ptr<ParallelogrammaticShape>& shapePtr);
}

#endif
