#ifndef GUI_SHAPE_MOVEMENT_H
#define GUI_SHAPE_MOVEMENT_H

#include <imgui.h>
#include <imgui-SFML.h>

#include "../aliases.h"
#include "../util.h"

#include "../events/ShapeMovement.h"

#include "../shapes/Figure.h"

void guiCheckForShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForCircularShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForQuadrangularShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

#endif
