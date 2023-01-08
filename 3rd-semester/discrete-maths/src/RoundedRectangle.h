#ifndef ROUNDED_RECTANGLE_H
#define ROUNDED_RECTANGLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class RoundedRectangle
{
public:
	RoundedRectangle() = default;

	void setSize(const sf::Vector2f& size);
	void setFillColor(const sf::Color& color);
	void setPosition(const sf::Vector2f& position);

	bool isMouseOnShape(const sf::Vector2f& mousePosition) const;

	void draw(sf::RenderWindow& window) const;

private:
	sf::RectangleShape m_rectangle{};
	sf::CircleShape m_leftCircle{};
	sf::CircleShape m_rightCircle{};
};

#endif
