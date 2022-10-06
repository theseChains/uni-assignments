#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include "../util.h"
#include "../aliases.h"

#include "ShapeMovement.h"
#include "ShapeModification.h"
#include "ShapeArrayCreation.h"
#include "ShapeVisibilityModification.h"

#include "../shapes/Figure.h"

#include "../containers/DynamicArray.h"
#include "../containers/DynamicList.h"

void handleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void handleShapeListEvents(DynamicList<std::shared_ptr<Figure>>& shapesToRender);

#endif
