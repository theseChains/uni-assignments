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
#include "../containers/DynamicList.h"

namespace Modification
{
    void checkForCircularShapeArrayModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void checkForCircularShapeListModification(DynamicList<std::unique_ptr<Figure>>& shapesToRender);

    // auxiliary
    void enlargeCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);
    void reduceCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void enlargeCircularListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender);
    void reduceCircularListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender);
}

#endif
