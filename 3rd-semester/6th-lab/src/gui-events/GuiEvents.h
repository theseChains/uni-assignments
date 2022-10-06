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

#include "../containers/DynamicArray.h"

void guiHandleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForShapeVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForCircularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForQuadrangularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

#endif
