#ifndef GUI_EVENTS_H
#define GUI_EVENTS_H

#include <imgui.h>
#include <imgui-SFML.h>

#include <array>
#include <memory>
#include <vector>

#include "../aliases.h"
#include "../util.h"

#include "../events/Events.h"

#include "GuiShapeCreation.h"
#include "GuiShapeArrayCreation.h"
#include "GuiShapeModification.h"
#include "GuiShapeMovement.h"

void guiHandleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender);
void guiHandleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void guiHandleEllipseEvents(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender,
        VectorOfArrayOfEllipsePtrs& ellipseArraysToRender);
void guiHandleQuadrangleEvents(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender,
        VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender);
void guiHandleRhombusEvents(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender,
        VectorOfArrayOfRhombusPtrs& rhombusArraysToRender);
void guiHandleTrapezoidEvents(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender,
        VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender);

void guiHandleCircleArrayCreation(VectorOfArrayOfCirclePtrs& circleArraysToRender);
void guiHandleRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void guiHandleEllipseArrayCreation(VectorOfArrayOfEllipsePtrs& ellipseArraysToRender);
void guiHandleQuadrangleArrayCreation(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender);
void guiHandleRhombusArrayCreation(VectorOfArrayOfRhombusPtrs& rhombusArraysToRender);
void guiHandleTrapezoidArrayCreation(VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender);

#endif
