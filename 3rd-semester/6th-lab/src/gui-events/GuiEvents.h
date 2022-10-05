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

#include "GuiShapeArrayCreation.h"
#include "GuiShapeModification.h"
#include "GuiShapeMovement.h"

void guiHandleShapeArrayEvents(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void guiCheckForShapeVisibilityModification(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void guiCheckForCircularShapeVisibilityModification(
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

void guiCheckForQuadrangularShapeVisibilityModification(
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

#endif
