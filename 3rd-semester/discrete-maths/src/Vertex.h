#ifndef VERTEX_CLASS_H
#define VERTEX_CLASS_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class Vertex
{
private:
	sf::CircleShape m_circle{};
	sf::Text m_label{};

public:
	Vertex(const sf::Vector2f& mousePosition, const sf::Font& labelFont, std::size_t index);

	sf::CircleShape getCircle() const;
	sf::Text getLabel() const;

	void setCircleColor(const sf::Color& color);

private:
	sf::CircleShape createCircleShape(const sf::Vector2f& mousePosition);
	sf::Text createLabelText(const sf::Vector2f& circlePosition, const sf::Font& labelFont,
			std::size_t index);
};

#endif
