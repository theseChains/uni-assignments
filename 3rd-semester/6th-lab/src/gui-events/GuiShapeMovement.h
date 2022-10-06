#ifndef GUI_SHAPE_MOVEMENT_H
#define GUI_SHAPE_MOVEMENT_H

#include <imgui.h>
#include <imgui-SFML.h>

#include "../aliases.h"
#include "../util.h"

#include "../events/ShapeMovement.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"
#include "../shapes/Trapezoid.h"

void guiCheckForShapeMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForCircularShapeMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForQuadrangularShapeMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

#endif
