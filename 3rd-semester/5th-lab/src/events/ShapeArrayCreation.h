#ifndef SHAPE_ARRAY_CREATION_H
#define SHAPE_ARRAY_CREATION_H

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"
#include "../shapes/Trapezoid.h"

#include "CircularShapeCreation.h"
#include "ParallelogrammaticShapeCreation.h"
#include "QuadrangleShapeCreation.h"
#include "TrapezoidShapeCreation.h"

namespace ArrayCreation
{
    void checkForShapeCreation(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
    void checkForShapeDeletion(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

    void createRandomShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
    void deleteAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
}

#endif
