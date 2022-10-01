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
        std::optional<sf::CircleShape> optCircleShape{};
        std::optional<sf::RectangleShape> optRectangleShape{};

        sf::RectangleShape rectValue() const
        {
            return optRectangleShape.value();
        }

        sf::CircleShape circleValue() const
        {
            return optCircleShape.value();
        }

        // overload std::optional<sf::CircleShape> cast - provide a way to convert this ToShow
        // struct to the optional<> type.
        // with this we can overload a funciton that differ only by return types
        operator std::optional<sf::CircleShape>() const { return optCircleShape; };
        operator std::optional<sf::RectangleShape>() const { return optRectangleShape; };
    };

    virtual ToShow show(bool modifyVisibility = true) = 0;

    virtual void moveTo(float offsetX, float offsetY) = 0;

    Vertex getPosition() const;

    virtual ~Figure() = default;

protected:
    Vertex m_vertex{};
};

#endif
