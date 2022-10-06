#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include "../util.h"
#include "../aliases.h"

#include "ShapeMovement.h"
#include "ShapeModification.h"
#include "ShapeArrayCreation.h"

#include "../shapes/Figure.h"

#include "../containers/DynamicArray.h"

void handleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void checkForShapeVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void checkForCircularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void checkForQuadrangularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void showAllShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void hideAllShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void showCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void hideCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void showQuadrangularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void hideQuadrangularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

#endif
