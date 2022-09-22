#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include <memory>

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Line.h"

void checkForCircleShapeCreation(std::vector<std::unique_ptr<Circle>>& circlesToRender);
void checkForRectangleShapeCreation(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender);
void checkForLineShapeCreation(std::array<std::unique_ptr<Line>, 3>& linesToRender);

void checkForCircleModification(std::vector<std::unique_ptr<Circle>>& circlesToRender);
void checkForRectangleModification(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender);
void checkForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender);

// made for Circle and Line shape creation since they have the same constructor parameters
namespace Creation
{
    template <typename ShapeType>
    void checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender);

    // auxiliary funcitons
    template <typename ShapeType>
    void hideAndDelete(std::unique_ptr<ShapeType>& oldShapePtr);

    template <typename ShapeType>
    void createAndShowDefaultShape(std::unique_ptr<ShapeType>& newShapePtr);

    template <typename ShapeType>
    void createAndShowFirstConstructorShape(std::unique_ptr<ShapeType>& newShapePtr);

    template <typename ShapeType>
    void createAndShowSecondConstructorShape(std::unique_ptr<ShapeType>& newShapePtr);
}

namespace Movement
{
    template <typename ShapeType>
    void checkForShapeMovement(std::vector<std::unique_ptr<ShapeType>>& shapesToRender);
}

#endif
