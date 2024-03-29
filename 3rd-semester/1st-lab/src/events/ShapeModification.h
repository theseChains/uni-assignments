#ifndef SHAPE_MODIFICATION_H
#define SHAPE_MODIFICATION_H

#include <array>
#include <memory>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

void checkForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender);
void checkForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void checkForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender);

void checkForCircleArrayModification(VectorOfArrayOfCirclePtrs& circleArraysToRender);
void checkForRectangleArrayModification(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void checkForLineArrayModification(VectorOfArrayOfLinePtrs& lineArraysToRender);

// auxiliary
void enlargeCircles(std::array<std::unique_ptr<Circle>, 3>& circlesToRender);
void reduceCircles(std::array<std::unique_ptr<Circle>, 3>& circlesToRender);

void reduceHeightOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void reduceWidthOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void increaseHeightOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void increaseWidthOfRectangles(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);

void rotateLinesClockwise(std::array<std::unique_ptr<Line>, 3>& linesToRender);
void rotateLinesCounterClockwise(std::array<std::unique_ptr<Line>, 3>& linesToRender);

#endif
