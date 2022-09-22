#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

void checkForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender);
void checkForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void checkForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender);

#endif
