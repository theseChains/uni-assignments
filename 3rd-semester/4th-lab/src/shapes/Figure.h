#ifndef FIGURE_BASE_H
#define FIGURE_BASE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <optional>

#include "../util.h"

#include "Vertex.h"

class Figure
{
public:
    Figure(float mainPointX, float mainPointY, const sf::Color& color);
    Figure(float mainPointX, float mainPointY, const std::array<int, 4>& colorComponents);

    // struct to overload the show() function for different shapes
    struct ToShow
    {
    private:
        std::optional<sf::CircleShape> m_optCircleShape{};
        std::optional<sf::RectangleShape> m_optRectangleShape{};
        std::optional<sf::ConvexShape> m_optConvexShape{};

    public:
        ToShow() = default;
        ToShow(const std::optional<sf::CircleShape>& optCircleShape);
        ToShow(const std::optional<sf::RectangleShape>& optRectangleShape);
        ToShow(const std::optional<sf::ConvexShape>& optConvexShape);

        sf::RectangleShape rectValue() const;
        sf::CircleShape circleValue() const;
        sf::ConvexShape convexValue() const;
    };

    virtual ToShow show([[maybe_unused]] bool modifyVisibility = true) { return ToShow{}; };

    void moveTo(float offsetX, float offsetY);

    Vertex getPosition() const;

    virtual ~Figure() = default;

protected:
    Vertex m_vertex{};
    Vertex m_secondVertex{};
    Vertex m_thirdVertex{};
    Vertex m_fourthVertex{};

    bool m_isShown{};

    bool m_isQuadrangle{};

    sf::Color m_color{};
};

#endif
