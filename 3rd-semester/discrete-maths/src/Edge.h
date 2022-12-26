#ifndef EDGE_CLASS_H
#define EDGE_CLASS_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include <cstddef>

class Edge
{
private:
	sf::RectangleShape m_line{};
	std::size_t m_rowIndex{};
	std::size_t m_columnIndex{};

public:
	Edge(std::size_t rowIndex, std::size_t columnIndex, const sf::Vector2f& firstVertexPosition,
			const sf::Vector2f& secondVertexPosition);

	sf::RectangleShape createLineShape(const sf::Vector2f& firstVertexPosition,
			const sf::Vector2f& secondVertexPosition);

	sf::RectangleShape getLine() const;
	std::size_t getRow() const;
	std::size_t getColumn() const;

private:
	float calculateLineLength(const sf::Vector2f& firstVertexPosition,
			const sf::Vector2f& secondVertexPosition);
	float calculateLineRotation(const sf::Vector2f& firstVertexPosition,
			const sf::Vector2f& secondVertexPosition);
	sf::Color calculateLineColor();
};

#endif
