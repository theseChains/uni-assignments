#ifndef SHAPE_MODIFICATION_H
#define SHAPE_MODIFICATION_H

#include <array>
#include <memory>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"
#include "../shapes/Rhombus.h"
#include "../shapes/Trapezoid.h"

namespace Modification
{
    // for Circle
    template <typename CircularShape>
    void checkForCircularShapeModification(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    template <typename CircularShape>
    void checkForCircularShapeArrayModification(
            VectorOfArrayOfCircularShapePtrs<CircularShape>& shapeArraysToRender);

    // for Rectangle
    void checkForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);

    void checkForRectangleArrayModification(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

    // for Ellipse
    void checkForEllipseShapeModification(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender);

    void checkForEllipseArrayModification(VectorOfArrayOfEllipsePtrs& ellipseArraysToRender);

    // for Rhombus
    void checkForRhombusShapeModification(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender);

    void checkForRhombusArrayModification(VectorOfArrayOfRhombusPtrs& rhombusArraysToRender);

    // for Trapezoid
    void checkForTrapezoidShapeModification(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender);

    void checkForTrapezoidArrayModification(VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender);

    // auxiliary
    template <typename CircularShape>
    void enlargeCircles(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    template <typename CircularShape>
    void reduceCircles(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    void reduceHeightOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
    void reduceWidthOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
    void increaseHeightOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
    void increaseWidthOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);

    template <typename LineShape>
    void rotateLinesClockwise(std::array<std::unique_ptr<LineShape>, 3>& linesToRender);

    template <typename LineShape>
    void rotateLinesCounterClockwise(std::array<std::unique_ptr<LineShape>, 3>& linesToRender);

    void rotateByNinetyDegrees(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender);

    void reduceHeightOfRhombuses(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender);
    void reduceWidthOfRhombuses(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender);
    void increaseHeightOfRhombuses(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender);
    void increaseWidthOfRhombuses(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender);

    void reduceHeightOfTrapezoids(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender);
    void reduceWidthOfTrapezoids(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender);
    void increaseHeightOfTrapezoids(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender);
    void increaseWidthOfTrapezoids(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender);
}

#endif
