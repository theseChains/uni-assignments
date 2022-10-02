#ifndef GUI_SHAPE_CREATION_H
#define GUI_SHAPE_CREATION_H

#include <imgui.h>
#include <imgui-SFML.h>

#include <array>
#include <memory>

#include "../aliases.h"
#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"

#include "../events/ShapeCreation.h"

namespace GuiCreation
{
    template <typename ShapeType>
    void checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender);

    void checkForRectangleCreation(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
}

#endif
