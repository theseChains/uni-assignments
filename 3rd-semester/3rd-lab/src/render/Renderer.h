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
#include "../shapes/Line.h"
#include "../shapes/Ellipse.h"

class Renderer
{
public:
    std::reference_wrapper<sf::RenderWindow> m_window;

public:
    Renderer(sf::RenderWindow& window);

    // Rectangle and Line
    template <typename RectangleShape>
    void renderRectangleShapes(std::array<std::unique_ptr<RectangleShape>, 3>& shapesToRender);

    // Circle and Ellipse
    template <typename CircularShape>
    void renderCircleShapes(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    template <typename RectangleShape>
    void renderRectangleShapeArrays(VectorOfArrayOfShapePtrs<RectangleShape>& arraysToRender);

    template <typename CircularShape>
    void renderCircleShapeArrays(VectorOfArrayOfCircularShapePtrs<CircularShape>& circleArraysTorender);
};

#endif
