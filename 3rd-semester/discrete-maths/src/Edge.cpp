#include "Edge.h"
#include "Constants.h"

Edge::Edge(std::size_t rowIndex, std::size_t columnIndex, const sf::Vector2f& firstVertexPosition,
		const sf::Vector2f& secondVertexPosition)
	: m_line{}, m_rowIndex{ rowIndex }, m_columnIndex{ columnIndex }
{
	m_line = createLineShape(firstVertexPosition, secondVertexPosition);
}

sf::RectangleShape Edge::createLineShape(const sf::Vector2f& firstVertexPosition,
		const sf::Vector2f& secondVertexPosition)
{
	sf::RectangleShape line{
		{ getLineLength(firstVertexPosition, secondVertexPosition), 3.0f } };
	sf::Color edgeColor{ getLineColor() };
	float edgeRotationAngle{ getLineRotation(firstVertexPosition, secondVertexPosition) };

	line.setPosition(firstVertexPosition + sf::Vector2f{ constants::vertexRadius,
			constants::vertexRadius });
	line.setFillColor(edgeColor);
	line.setRotation(edgeRotationAngle);

	return line;
}

float Edge::getLineLength(const sf::Vector2f& firstPosition,
		const sf::Vector2f& secondPosition)
{
	return (static_cast<float>(std::sqrt(std::pow((secondPosition.x - firstPosition.x), 2) +
			std::pow((secondPosition.y - firstPosition.y), 2))));
}

float Edge::getLineRotation(const sf::Vector2f& firstPosition,
		const sf::Vector2f& secondPosition)
{
	auto slope{ (firstPosition.y - secondPosition.y) / (firstPosition.x - secondPosition.x) };
	float angle{ static_cast<float>(atan(slope)) * 180.0f / std::numbers::pi_v<float> };
	if (firstPosition.x >= secondPosition.x)
		angle += 180.0f;
	return angle;
}

sf::Color Edge::getLineColor()
{
	sf::Color color{ rnd::getUchar(0, 200), rnd::getUchar(0, 200), rnd::getUchar(205, 255) };
	return { color };
}

sf::RectangleShape Edge::getLine() const
{
	return m_line;
}

std::size_t Edge::getRow() const
{
	return m_rowIndex;
}

std::size_t Edge::getColumn() const
{
	return m_columnIndex;
}
