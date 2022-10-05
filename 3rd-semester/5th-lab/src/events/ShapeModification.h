#ifndef SHAPE_MODIFICATION_H
#define SHAPE_MODIFICATION_H

#include <array>
#include <memory>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Figure.h"
#include "../shapes/Circle.h"
#include "../shapes/Ellipse.h"

namespace Modification
{
    void checkForCircularShapeModification(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);

    // auxiliary
    void enlargeCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
    void reduceCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
}

#endif
