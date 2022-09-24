#ifndef ALIASES_H
#define ALIASES_H

#include <array>
#include <memory>
#include <vector>

#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Line.h"

using vector_of_circle_arrays = std::vector<std::array<std::unique_ptr<Circle>, 3>>; 
using vector_of_rectangle_arrays = std::vector<std::array<std::unique_ptr<Rectangle>, 3>>; 
using vector_of_line_arrays = std::vector<std::array<std::unique_ptr<Line>, 3>>; 

#endif
