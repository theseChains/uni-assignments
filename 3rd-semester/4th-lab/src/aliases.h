#ifndef ALIASES_H
#define ALIASES_H

#include <array>
#include <memory>
#include <vector>

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Ellipse.h"
#include "shapes/Quadrangle.h"
#include "shapes/Rhombus.h"
#include "shapes/Trapezoid.h"

// all shapes
template <typename ShapeType>
using VectorOfArrayOfShapePtrs = std::vector<std::array<std::unique_ptr<ShapeType>, 3>>;

// Circle and Ellipse
template <typename CircularShape>
using VectorOfArrayOfCircularShapePtrs = std::vector<std::array<std::unique_ptr<CircularShape>, 3>>;

// Rectangle and Rhombus
template <typename ParallelogrammaticShape>
using VectorOfArrayOfParalellogramShapePtrs =
        std::vector<std::array<std::unique_ptr<ParallelogrammaticShape>, 3>>;

// Rectangle, Quadrangle, Trapezoid and Rhombus
template <typename QuadrangularShape>
using VectorOfArrayOfQuadrangularShapePtrs =
        std::vector<std::array<std::unique_ptr<QuadrangularShape>, 3>>;

using VectorOfArrayOfCirclePtrs = std::vector<std::array<std::unique_ptr<Circle>, 3>>;
using VectorOfArrayOfRectanglePtrs = std::vector<std::array<std::unique_ptr<Rectangle>, 3>>;
using VectorOfArrayOfEllipsePtrs = std::vector<std::array<std::unique_ptr<Ellipse>, 3>>;
using VectorOfArrayOfQuadranglePtrs = std::vector<std::array<std::unique_ptr<Quadrangle>, 3>>;
using VectorOfArrayOfRhombusPtrs = std::vector<std::array<std::unique_ptr<Rhombus>, 3>>;
using VectorOfArrayOfTrapezoidPtrs = std::vector<std::array<std::unique_ptr<Trapezoid>, 3>>;

#endif
