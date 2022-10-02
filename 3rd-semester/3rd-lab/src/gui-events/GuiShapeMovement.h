#ifndef GUI_SHAPE_MOVEMENT_H
#define GUI_SHAPE_MOVEMENT_H

#include <imgui.h>
#include <imgui-SFML.h>

#include "../aliases.h"
#include "../util.h"

#include "../events/ShapeMovement.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"

template <typename ShapeType>
void guiCheckForShapeMovement(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender,
        VectorOfArrayOfShapePtrs<ShapeType>& shapeArraysToRender);

#endif
