#include "Vertex.h"
#include "Constants.h"
#include "Colors.h"

Vertex::Vertex(const sf::Vector2f& mousePosition, const sf::Font& labelFont, std::size_t index)
	: m_circle{}, m_label{}
{
	m_circle = createCircleShape(mousePosition);
	m_label = createLabelText(m_circle.getPosition(), labelFont, index);
}

sf::CircleShape Vertex::createCircleShape(const sf::Vector2f& mousePosition)
{
	sf::CircleShape circle{ constants::vertexRadius };
	circle.setPosition(mousePosition -
			sf::Vector2f{ constants::vertexRadius, constants::vertexRadius });
	circle.setFillColor(color::vertex);

	return circle;
}

sf::Text Vertex::createLabelText(const sf::Vector2f& circlePosition, const sf::Font& labelFont,
		std::size_t index)
{
	sf::Text label{ "v" + std::to_string(index), labelFont, constants::vertexLabelFontSize };
	label.setFillColor(color::label);
	label.setPosition(circlePosition + sf::Vector2f{ constants::vertexRadius / 2 - 3.0f,
			constants::vertexRadius / 2 - 4.0f });

	return label;
}

const sf::CircleShape& Vertex::getCircle() const
{
	return m_circle;
}

const sf::Text& Vertex::getLabel() const
{
	return m_label;
}

void Vertex::setCircleColor(const sf::Color& color)
{
	m_circle.setFillColor(color);
}

void Vertex::setLabelColor(const sf::Color& color)
{
	m_label.setFillColor(color);
}

void Vertex::setCirclePointCount(std::size_t pointCount)
{
	m_circle.setPointCount(pointCount);
}

void Vertex::setLabelText(const std::string& text)
{
	m_label.setString(text);
}

const sf::Color& Vertex::getCircleFillColor() const
{
	return m_circle.getFillColor();
}

std::size_t Vertex::getCirclePointCount() const
{
	return m_circle.getPointCount();
}

const sf::Vector2f& Vertex::getCirclePosition() const
{
	return m_circle.getPosition();
}

sf::FloatRect Vertex::getCircleGlobalBounds() const
{
	return m_circle.getGlobalBounds();
}

int Vertex::getIndexFromLabel() const
{
	return m_label.getString()[1] - '0';
}

bool Vertex::operator==(const Vertex& other) const
{
	return (m_label.getString() == other.m_label.getString());
}
