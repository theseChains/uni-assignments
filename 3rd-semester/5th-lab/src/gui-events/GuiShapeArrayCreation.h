#ifndef GUI_SHAPE_ARRAY_CREATION_H
#define GUI_SHAPE_ARRAY_CREATION_H

#include <imgui.h>
#include <imgui-SFML.h>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"
#include "../shapes/Rhombus.h"
#include "../shapes/Trapezoid.h"

#include "../events/ShapeArrayCreation.h"

namespace GuiArrayCreation
{
    void checkForShapeCreation(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
    void checkForShapeDeletion(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
}

#endif
