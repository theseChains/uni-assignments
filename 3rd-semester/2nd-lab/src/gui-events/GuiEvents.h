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
#include "../shapes/Ring.h"

#include "GuiShapeCreation.h"
#include "GuiShapeArrayCreation.h"
#include "GuiShapeModification.h"
#include "GuiShapeMovement.h"

void guiHandleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender);
void guiHandleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void guiHandleLineEvents(std::array<std::unique_ptr<Line>, 3>& linesToRender,
        VectorOfArrayOfLinePtrs& lineArraysToRender);
void guiHandleRingEvents(std::array<std::unique_ptr<Ring>, 3>& ringsToRender,
        VectorOfArrayOfRingPtrs& ringArraysToRender);

void guiHandleCircleArrayCreation(VectorOfArrayOfCirclePtrs& circleArraysToRender);
void guiHandleRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void guiHandleLineArrayCreation(VectorOfArrayOfLinePtrs& lineArraysToRender);
void guiHandleRingArrayCreation(VectorOfArrayOfRingPtrs& ringArraysToRender);

#endif
