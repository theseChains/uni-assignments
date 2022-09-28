#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include "../util.h"
#include "../aliases.h"

#include "ShapeCreation.h"
#include "ShapeMovement.h"
#include "ShapeModification.h"
#include "ShapeArrayCreation.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"
#include "../shapes/Ring.h"

void handleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender);
void handleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void handleLineEvents(std::array<std::unique_ptr<Line>, 3>& linesToRender);
void handleRingEvents(std::array<std::unique_ptr<Ring>, 3>& ringsToRender);

void handleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circleArraysToRender);
void handleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void handleLineArrayEvents(VectorOfArrayOfLinePtrs& lineArraysToRender);
void handleRingArrayEvents(VectorOfArrayOfRingPtrs& ringArraysToRender);

#endif
