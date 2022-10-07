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

#include "../containers/DynamicArray.h"
#include "../containers/DynamicList.h"

namespace GuiArrayCreation
{
    void checkForShapeArrayCreation(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
    void checkForShapeArrayDeletion(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void checkForShapeListCreation(DynamicList<std::unique_ptr<Figure>>& shapesToRender);
    void checkForShapeListDeletion(DynamicList<std::unique_ptr<Figure>>& shapesToRender);
}

#endif
