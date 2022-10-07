#ifndef GUI_SHAPE_VISIBILITY_MODIFICATION_H
#define GUI_SHAPE_VISIBILITY_MODIFICATION_H

#include <imgui.h>
#include <imgui-SFML.h>

#include "../util.h"

#include "../events/ShapeVisibilityModification.h"

#include "../shapes/Figure.h"

void guiCheckForShapeArrayVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForCircularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForQuadrangularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForShapeListVisibilityModification(DynamicList<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForCircularShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender);

void guiCheckForQuadrangularShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender);

#endif
