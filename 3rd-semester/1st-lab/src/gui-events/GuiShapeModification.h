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
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

void guiCheckForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender);
void guiCheckForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void guiCheckForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender,
        VectorOfArrayOfLinePtrs& lineArraysToRender);

#endif
