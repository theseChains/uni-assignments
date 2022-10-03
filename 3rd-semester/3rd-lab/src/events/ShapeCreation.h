#ifndef SHAPE_CREATION_H
#define SHAPE_CREATION_H

#include <array>
#include <memory>

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"

// todo: split this into 3 files
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

    // for Quadrangle class
    void checkForQuadrangleShapeCreation(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender);

    void createAndShowDefaultQuadrangle(std::unique_ptr<Quadrangle>& newQuadranglePtr);
    Quadrangle createFirstConstructorQuadrangle();
    Quadrangle createSecondConstructorQuadrangle();

    void handleDefaultQuadrangleShapeCreation(std::unique_ptr<Quadrangle>& quadranglePtr);
    void handleFirstConstructorQuadrangleCreation(std::unique_ptr<Quadrangle>& quadranglePtr);
    void handleSecondConstructorQuadrangleCreation(std::unique_ptr<Quadrangle>& quadranglePtr);
}

#endif
