#ifndef CIRCULAR_SHAPE_CREATION_H
#define CIRCULAR_SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Ellipse.h"

#include "ShapeCreationAuxiliary.h"

namespace Creation
{
    // for Circle and Ellipse classes
    template <typename CircularShape>
    void checkForCircularShapeCreation(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    // auxiliary funcitons
    template <typename ShapeType>
    void hideAndDeleteShape(std::unique_ptr<ShapeType>& oldShapePtr);

    template <typename CircularShape>
    void createAndShowDefaultCircularShape(std::unique_ptr<CircularShape>& newShapePtr);

    template <typename CircularShape>
    CircularShape createFirstConstructorCircularShape();

    template <typename CircularShape>
    CircularShape createSecondConstructorCircularShape();

    template <typename CircularShape>
    void handleDefaultCircularShapeCreation(std::unique_ptr<CircularShape>& shapePtr);

    template <typename CircularShape>
    void handleFirstConstructorCircularShapeCreation(std::unique_ptr<CircularShape>& shapePtr);

    template <typename CircularShape>
    void handleSecondConstructorCircularShapeCreation(std::unique_ptr<CircularShape>& shapePtr);
}

#endif
