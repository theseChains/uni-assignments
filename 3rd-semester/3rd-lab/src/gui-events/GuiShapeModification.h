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

// for Circle and ...
template <typename CircularShape>
void guiCheckForCircularShapeModification(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender,
       VectorOfArrayOfCircularShapePtrs<CircularShape>& shapeArraysToRender);

// for Rectangle
void guiCheckForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

// for Line and ...
template <typename LineShape>
void guiCheckForLineShapeModification(std::array<std::unique_ptr<LineShape>, 3>& linesToRender,
        VectorOfArrayOfLineShapePtrs<LineShape>& lineArraysToRender);

// for Ellipse
void guiCheckForEllipseShapeModification(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender,
        VectorOfArrayOfEllipsePtrs& ellipseArraysToRender);
#endif
