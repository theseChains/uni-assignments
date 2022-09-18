#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include <memory>

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

void checkForCircleShapeCreation(std::vector<std::unique_ptr<Circle>>& circlesToRender);
void checkForRectangleShapeCreation(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender);
void checkForLineShapeCreation(std::vector<std::unique_ptr<Line>>& linesToRender);

void checkForCircleModification(std::vector<std::unique_ptr<Circle>>& circlesToRender);
void checkForRectangleModification(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender);
void checkForLineModification(std::vector<std::unique_ptr<Line>>& linesToRender);

#endif
