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

	const sf::CircleShape& getCircle() const;
	const sf::Text& getLabel() const;

	void setCircleColor(const sf::Color& color);
	void setLabelColor(const sf::Color& color);
	void setCirclePointCount(std::size_t pointCount);
	void setLabelText(const std::string& text);

	const sf::Color& getCircleFillColor() const;
	std::size_t getCirclePointCount() const;
	const sf::Vector2f& getCirclePosition() const;
	sf::FloatRect getCircleGlobalBounds() const;
	int getIndexFromLabel() const;

	bool operator==(const Vertex& other) const;

private:
	sf::CircleShape createCircleShape(const sf::Vector2f& mousePosition);
	sf::Text createLabelText(const sf::Vector2f& circlePosition, const sf::Font& labelFont,
			std::size_t index);
};

#endif
