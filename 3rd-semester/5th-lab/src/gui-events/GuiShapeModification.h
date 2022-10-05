#ifndef GUI_SHAPE_MODIFICATION_H
#define GUI_SHAPE_MODIFICATION_H

#include <imgui.h>
#include <imgui-SFML.h>

#include <array>
#include <memory>

#include "../util.h"
#include "../aliases.h"

#include "../events/ShapeModification.h"

#include "../shapes/Circle.h"
#include "../shapes/Ellipse.h"

void guiCheckForCircularShapeModification(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

#endif
