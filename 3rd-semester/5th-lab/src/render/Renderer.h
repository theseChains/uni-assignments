#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include <array>
#include <functional>
#include <memory>
#include <vector>

#include "../util.h"
#include "../aliases.h"

#include "../shapes/Figure.h"

class Renderer
{
public:
    std::reference_wrapper<sf::RenderWindow> m_window;

public:
    Renderer(sf::RenderWindow& window);

    // all shapes array
    void renderShapeArray(std::array<std::unique_ptr<Figure>, 30>& shapesToRender);
};

#endif
