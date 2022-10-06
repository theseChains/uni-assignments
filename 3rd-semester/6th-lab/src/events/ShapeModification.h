#ifndef SHAPE_MODIFICATION_H
#define SHAPE_MODIFICATION_H

#include <array>
#include <memory>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Figure.h"
#include "../shapes/Circle.h"
#include "../shapes/Ellipse.h"

#include "../containers/DynamicArray.h"

namespace Modification
{
    void checkForCircularShapeModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    // auxiliary
    void enlargeCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
    void reduceCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
}

#endif
