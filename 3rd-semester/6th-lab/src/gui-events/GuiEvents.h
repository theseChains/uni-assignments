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
#include "GuiShapeVisibilityModification.h"

void guiHandleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiHandleShapeListEvents(DynamicList<std::unique_ptr<Figure>>& shapesToRender);

#endif
