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
#include "../shapes/Ring.h"
#include "../shapes/Asterisk.h"

// for Circle and Ring classes
template <typename CircularShape>
void guiCheckForCircularShapeModification(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender,
       VectorOfArrayOfCircularShapePtrs<CircularShape>& shapeArraysToRender);

void guiCheckForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

// for Line and Asterisk classes
template <typename LineShape>
void guiCheckForLineShapeModification(std::array<std::unique_ptr<LineShape>, 3>& linesToRender,
        VectorOfArrayOfLineShapePtrs<LineShape>& lineArraysToRender);

#endif
