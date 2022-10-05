#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include "../util.h"
#include "../aliases.h"

#include "ShapeMovement.h"
#include "ShapeModification.h"
#include "ShapeArrayCreation.h"

#include "../shapes/Figure.h"

void handleShapeArrayEvents(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void checkForShapeVisibilityModification(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void checkForCircularShapeVisibilityModification(
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void checkForQuadrangularShapeVisibilityModification(
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void showAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void hideAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void showCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void hideCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void showQuadrangularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
void hideQuadrangularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

#endif
