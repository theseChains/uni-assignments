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

#include "../containers/DynamicArray.h"

namespace ArrayCreation
{
    void checkForShapeCreation(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
    void checkForShapeDeletion(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void createRandomShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
    void deleteAllShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
}

#endif
