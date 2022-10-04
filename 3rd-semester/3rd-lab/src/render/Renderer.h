#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include <array>
#include <functional>
#include <memory>
#include <vector>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"
#include "../shapes/Rhombus.h"

class Renderer
{
public:
    std::reference_wrapper<sf::RenderWindow> m_window;

public:
    Renderer(sf::RenderWindow& window);

    // Rectangle, Quadrangle and Rhombus
    template <typename QuadrangularShape>
    void renderQuadrangularShapes(std::array<std::unique_ptr<QuadrangularShape>, 3>& shapesToRender);

    // Circle and Ellipse
    template <typename CircularShape>
    void renderCircleShapes(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    // Rectangle, Quadrangle and Rhombus arrays
    template <typename QuadrangularShape>
    void renderQuadrangularShapeArrays(
            VectorOfArrayOfQuadrangularShapePtrs<QuadrangularShape>& arraysToRender);

    // Circle arrays
    template <typename CircularShape>
    void renderCircleShapeArrays(VectorOfArrayOfCircularShapePtrs<CircularShape>& circleArraysTorender);
};

#endif
