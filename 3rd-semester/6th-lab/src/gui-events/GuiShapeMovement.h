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

void guiCheckForShapeMovement(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void guiCheckForCircularShapeMovement(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void guiCheckForQuadrangularShapeMovement(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

#endif
