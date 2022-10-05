#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include "../util.h"
#include "../aliases.h"

#include "CircularShapeCreation.h"
#include "ParallelogrammaticShapeCreation.h"
#include "QuadrangleShapeCreation.h"
#include "TrapezoidShapeCreation.h"

#include "ShapeMovement.h"
#include "ShapeModification.h"
#include "ShapeArrayCreation.h"

#include "../shapes/Figure.h"

void handleShapeArrayEvents(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void createRandomShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void showAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void hideAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void moveAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
        float verticalDirection = 0.0f, float horizontalDirection = 0.0f);
void deleteAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void showCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void hideCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

#endif
