#ifndef SHAPE_VISIBILITY_MODIFICATION_H
#define SHAPE_VISIBILITY_MODIFICATION_H

#include <SFML/Graphics.hpp>

#include "../shapes/Circle.h"
#include "../shapes/Quadrangle.h"

#include "../containers/DynamicArray.h"
#include "../containers/DynamicList.h"

void checkForShapeArrayVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void checkForShapeListVisibilityModification(DynamicList<std::unique_ptr<Figure>>& shapesToRender);

void showShape(std::unique_ptr<Figure>& shape);
void hideShape(std::unique_ptr<Figure>& shape);

void checkForCircularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void checkForCircularShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender);

void showCircularShape(std::unique_ptr<Figure>& shape);
void hideCircularShape(std::unique_ptr<Figure>& shape);

void checkForQuadrangularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

void checkForQuadrangularShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender);

void showQuadrangularShape(std::unique_ptr<Figure>& shape);
void hideQuadrangularShape(std::unique_ptr<Figure>& shape);

#endif
