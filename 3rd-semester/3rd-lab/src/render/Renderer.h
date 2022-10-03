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

class Renderer
{
public:
    std::reference_wrapper<sf::RenderWindow> m_window;

public:
    Renderer(sf::RenderWindow& window);

    // Rectangle
    template <typename RectangleShape>
    void renderRectangleShapes(std::array<std::unique_ptr<RectangleShape>, 3>& shapesToRender);

    // Circle and Ellipse
    template <typename CircularShape>
    void renderCircleShapes(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender);

    // Quadrangle
    void renderQuadrangleShapes(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender);

    // Rectangle arrays
    template <typename RectangleShape>
    void renderRectangleShapeArrays(VectorOfArrayOfShapePtrs<RectangleShape>& arraysToRender);

    // Circle arrays
    template <typename CircularShape>
    void renderCircleShapeArrays(VectorOfArrayOfCircularShapePtrs<CircularShape>& circleArraysTorender);

    // Quadrangle arrays
    void renderQuadrangleShapeArrays(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender);
};

#endif
