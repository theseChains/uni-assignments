#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include "../util.h"

#include "ShapeCreation.h"
#include "ShapeMovement.h"
#include "ShapeModification.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

void circleEventHandlerFunction(std::array<std::unique_ptr<Circle>, 3>& circlesToRender);
void rectangleEventHandlerFunction(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void lineEventHandlerFunction(std::array<std::unique_ptr<Line>, 3>& linesToRender);

#endif
