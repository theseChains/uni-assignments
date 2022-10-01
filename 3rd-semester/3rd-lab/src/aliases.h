#ifndef ALIASES_H
#define ALIASES_H

#include <array>
#include <memory>
#include <vector>

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"
#include "shapes/Ellipse.h"

template <typename ShapeType>
using VectorOfArrayOfShapePtrs = std::vector<std::array<std::unique_ptr<ShapeType>, 3>>;

// Circle and Ellipse
template <typename CircularShape>
using VectorOfArrayOfCircularShapePtrs = std::vector<std::array<std::unique_ptr<CircularShape>, 3>>;

// Line and something.. 
template <typename LineShape>
using VectorOfArrayOfLineShapePtrs = std::vector<std::array<std::unique_ptr<LineShape>, 3>>;

using VectorOfArrayOfCirclePtrs = std::vector<std::array<std::unique_ptr<Circle>, 3>>;
using VectorOfArrayOfRectanglePtrs = std::vector<std::array<std::unique_ptr<Rectangle>, 3>>;
using VectorOfArrayOfLinePtrs = std::vector<std::array<std::unique_ptr<Line>, 3>>;
using VectorOfArrayOfEllipsePtrs = std::vector<std::array<std::unique_ptr<Ellipse>, 3>>;

#endif
