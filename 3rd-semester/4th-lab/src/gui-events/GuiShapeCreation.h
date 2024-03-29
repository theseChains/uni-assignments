#ifndef GUI_SHAPE_CREATION_H
#define GUI_SHAPE_CREATION_H

#include <imgui.h>
#include <imgui-SFML.h>

#include <array>
#include <memory>

#include "../aliases.h"
#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"
#include "../shapes/Rhombus.h"
#include "../shapes/Trapezoid.h"

#include "../events/CircularShapeCreation.h"
#include "../events/ParallelogrammaticShapeCreation.h"
#include "../events/QuadrangleShapeCreation.h"
#include "../events/TrapezoidShapeCreation.h"

namespace GuiCreation
{
    template <typename CircularShape>
    void checkForCircularShapeCreation(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    template <typename ParallelogrammaticShape>
    void checkForParallelogramCreation(
            std::array<std::unique_ptr<ParallelogrammaticShape>, 3>& shapesToRender);

    void checkForQuadrangleCreation(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender);

    void checkForTrapezoidCreation(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender);
}

#endif
