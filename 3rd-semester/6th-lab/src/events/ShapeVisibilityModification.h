#ifndef SHAPE_VISIBILITY_MODIFICATION_H
#define SHAPE_VISIBILITY_MODIFICATION_H

#include <SFML/Graphics.hpp>

#include "../shapes/Circle.h"
#include "../shapes/Quadrangle.h"

#include "../containers/DynamicArray.h"
#include "../containers/DynamicList.h"

void checkForShapeArrayVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void showAllArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void hideAllArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void checkForCircularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void showCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void hideCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void checkForQuadrangularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void showQuadrangularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
void hideQuadrangularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void checkForShapeListVisibilityModification(DynamicList<std::shared_ptr<Figure>>& shapesToRender);

void checkForSubShapeListVisibilityModification(
        DynamicList<std::shared_ptr<Figure>>& shapesToRender);

#endif
