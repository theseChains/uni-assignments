#ifndef SHAPE_MODIFICATION_H
#define SHAPE_MODIFICATION_H

#include <array>
#include <memory>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"
#include "../shapes/Ring.h"

namespace Modification
{
    // for Circle and Ring classes
    template <typename CircularShape>
    void checkForCircularShapeModification(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);
    
    void checkForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
    void checkForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender);
    
    template <typename CircularShape>
    void checkForCircularShapeArrayModification(
            VectorOfArrayOfCircularShapePtrs<CircularShape>& shapeArraysToRender);

    void checkForRectangleArrayModification(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
    void checkForLineArrayModification(VectorOfArrayOfLinePtrs& lineArraysToRender);
    
    // auxiliary
    template <typename CircularShape>
    void enlargeCircles(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);
    
    template <typename CircularShape>
    void reduceCircles(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);
    
    void reduceHeightOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
    void reduceWidthOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
    void increaseHeightOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
    void increaseWidthOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
    
    void rotateLinesClockwise(std::array<std::unique_ptr<Line>, 3>& linesToRender);
    void rotateLinesCounterClockwise(std::array<std::unique_ptr<Line>, 3>& linesToRender);
}

#endif
