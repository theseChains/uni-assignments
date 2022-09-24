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

class Renderer
{
public:
    std::reference_wrapper<sf::RenderWindow> m_window;

public:
    Renderer(sf::RenderWindow& window);

    template <typename ShapeType>
    void renderShapes(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender);

    template <typename ShapeType>
    void renderShapeArrays(std::vector<std::array<std::unique_ptr<ShapeType>, 3>>& arraysToRender);
};

#endif
