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

#include "../containers/DynamicArray.h"
#include "../containers/DynamicList.h"

class Renderer
{
public:
    std::reference_wrapper<sf::RenderWindow> m_window;

public:
    Renderer(sf::RenderWindow& window);

    // all shapes array
    void renderShapeArray(DynamicArray<std::unique_ptr<Figure>>& shapesToRender);

    void renderShapeList(DynamicList<std::shared_ptr<Figure>>& shapesToRender);
};

#endif
