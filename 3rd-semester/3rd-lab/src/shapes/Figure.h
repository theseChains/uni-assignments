#ifndef FIGURE_BASE_H
#define FIGURE_BASE_H

#include <SFML/Graphics.hpp>

#include <optional>

#include "Vertex.h"

class Figure
{
public:
    Figure(float mainPointX, float mainPointY);

    struct ToShow
    {
    private:
        std::optional<sf::CircleShape> m_optCircleShape{};
        std::optional<sf::RectangleShape> m_optRectangleShape{};

    public:
        ToShow() = default;
        ToShow(const std::optional<sf::CircleShape>& optCircleShape);
        ToShow(const std::optional<sf::RectangleShape>& optRectangleShape);

        sf::RectangleShape rectValue() const;
        sf::CircleShape circleValue() const;
    };

    virtual ToShow show(bool modifyVisibility = true) = 0;

    virtual void moveTo(float offsetX, float offsetY) = 0;

    Vertex getPosition() const;

    virtual ~Figure() = default;

protected:
    Vertex m_vertex{};
};

#endif
