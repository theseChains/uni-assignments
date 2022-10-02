#ifndef SHAPE_CREATION_H
#define SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"

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
