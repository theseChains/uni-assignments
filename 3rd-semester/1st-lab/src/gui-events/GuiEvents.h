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

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

#include "GuiShapeCreation.h"
#include "GuiShapeArrayCreation.h"

void guiHandleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender);
void guiHandleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void guiHandleLineEvents(std::array<std::unique_ptr<Line>, 3>& linesToRender);

void guiHandleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circelArraysToRender);
void guiHandleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void guiHandleLineArrayEvents(VectorOfArrayOfLinePtrs& lineArraysToRender);

#endif
