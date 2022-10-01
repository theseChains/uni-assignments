#ifndef SHAPE_CREATION_H
#define SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

namespace Creation
{
    // for Line, Circle and Ring classes
    template <typename ShapeType>
    void checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender);

    // auxiliary funcitons
    template <typename ShapeType>
    void hideAndDeleteShape(std::unique_ptr<ShapeType>& oldShapePtr);

    template <typename ShapeType>
    void createAndShowDefaultShape(std::unique_ptr<ShapeType>& newShapePtr);

    template <typename ShapeType>
    ShapeType createFirstConstructorShape();

    template <typename ShapeType>
    ShapeType createSecondConstructorShape();

    template <typename ShapeType>
    void handleDefaultShapeCreation(std::unique_ptr<ShapeType>& shapePtr);

    template <typename ShapeType>
    void handleFirstConstructorShapeCreation(std::unique_ptr<ShapeType>& shapePtr);

    template <typename ShapeType>
    void handleSecondConstructorShapeCreation(std::unique_ptr<ShapeType>& shapePtr);

    // for Rectangle class
    void checkForRectangleShapeCreation(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);

    // auxiliary functions
    void createAndShowDefaultRectangle(std::unique_ptr<Rectangle>& newRectanglePtr);
    Rectangle createFirstConstructorRectangle();
    Rectangle createSecondConstructorRectangle();

    void handleDefaultRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr);
    void handleFirstConstructorRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr);
    void handleSecondConstructorRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr);
}

#endif
