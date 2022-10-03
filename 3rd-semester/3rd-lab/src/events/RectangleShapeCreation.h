#ifndef RECTANGLE_SHAPE_CREATION_H
#define RECTANGLE_SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Rectangle.h"

#include "ShapeCreationAuxiliary.h"

namespace Creation
{
    void checkForRectangleShapeCreation(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);

    void createAndShowDefaultRectangle(std::unique_ptr<Rectangle>& newRectanglePtr);
    Rectangle createFirstConstructorRectangle();
    Rectangle createSecondConstructorRectangle();

    void handleDefaultRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr);
    void handleFirstConstructorRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr);
    void handleSecondConstructorRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr);
}

#endif
