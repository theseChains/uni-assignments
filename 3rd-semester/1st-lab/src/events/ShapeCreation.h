#ifndef SHAPE_CREATION_H
#define SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

// for Line and Circle classes
namespace Creation
{
    template <typename ShapeType>
    void checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender);

    // auxiliary funcitons
    template <typename ShapeType>
    void hideAndDelete(std::unique_ptr<ShapeType>& oldShapePtr);

    template <typename ShapeType>
    void createAndShowDefaultShape(std::unique_ptr<ShapeType>& newShapePtr);

    template <typename ShapeType>
    void createAndShowFirstConstructorShape(std::unique_ptr<ShapeType>& newShapePtr);

    template <typename ShapeType>
    void createAndShowSecondConstructorShape(std::unique_ptr<ShapeType>& newShapePtr);
}

// for Rectangle class
void checkForRectangleShapeCreation(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);

#endif
