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
#include "../shapes/Ellipse.h"
#include "../shapes/Rhombus.h"
#include "../shapes/Trapezoid.h"

// for Circle
void guiCheckForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
       VectorOfArrayOfCirclePtrs& circleArraysToRender);

// for Rectangle
void guiCheckForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);

// for Ellipse
void guiCheckForEllipseModification(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender,
        VectorOfArrayOfEllipsePtrs& ellipseArraysToRender);

// for Rhombus
void guiCheckForRhombusModification(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender,
        VectorOfArrayOfRhombusPtrs& rhombusArraysToRender);

// for Trapezoid
void guiCheckForTrapezoidModification(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender,
        VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender);

#endif
