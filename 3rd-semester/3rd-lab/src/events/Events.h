#ifndef EVENTS_UTILITY_FUNCTIONS
#define EVENTS_UTILITY_FUNCTIONS

#include "../util.h"
#include "../aliases.h"

#include "CircularShapeCreation.h"
#include "ParallelogrammaticShapeCreation.h"
#include "QuadrangleShapeCreation.h"

#include "ShapeMovement.h"
#include "ShapeModification.h"
#include "ShapeArrayCreation.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"
#include "../shapes/Rhombus.h"

void handleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender);
void handleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender);
void handleEllipseEvents(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender);
void handleQuadrangleEvents(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender);
void handleRhombusEvents(std::array<std::unique_ptr<Rhombus>, 3>& rhombusesToRender);

void handleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circleArraysToRender);
void handleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender);
void handleEllipseArrayEvents(VectorOfArrayOfEllipsePtrs& ellipseArraysToRender);
void handleQuadrangleArrayEvents(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender);
void handleRhombusArrayEvents(VectorOfArrayOfRhombusPtrs& rhombusArraysToRender);

#endif
