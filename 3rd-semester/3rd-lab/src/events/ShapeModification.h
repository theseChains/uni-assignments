#ifndef SHAPE_MODIFICATION_H
#define SHAPE_MODIFICATION_H

#include <array>
#include <memory>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

namespace Modification
{
    // for Circle and Ring classes
    template <typename CircularShape>
    void checkForCircularShapeModification(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    void checkForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);

    template <typename CircularShape>
    void checkForCircularShapeArrayModification(
            VectorOfArrayOfCircularShapePtrs<CircularShape>& shapeArraysToRender);

    void checkForRectangleArrayModification(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

    // for Line and Asterisk
    template <typename LineShape>
    void checkForLineShapeModification(std::array<std::unique_ptr<LineShape>, 3>& linesShapesToRender);

    template <typename LineShape>
    void checkForLineShapeArrayModification(VectorOfArrayOfLineShapePtrs<LineShape>& lineArraysToRender);

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
}

#endif
