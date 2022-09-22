#ifndef RECTANGLE_PRIMITIVE_H
#define RECTANGLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>

#include "../util.h"

class Rectangle
{
public:
    Rectangle();
    Rectangle(float topLeftX, float topLeftY, float width, float height, const sf::Color& color);
    Rectangle(float topLeftX, float topLeftY, float width, float height,
            const std::array<int, 4>& colorComponents);

    void show();

    void moveTo(float offsetX, float offsetY);

    void changeWidth(float widthOffset);
    void changeHeight(float heightOffset);
    
    sf::RectangleShape getSprite() const;

    bool isShown() const;

private:
    sf::RectangleShape m_sprite{};

    float m_topLeftX{};
    float m_topLeftY{};

    float m_width{};
    float m_height{};

    sf::Color m_color{};

    bool m_isShown{};

    void initializeSfSprite();
    void updateSfSprite();
};

#endif
