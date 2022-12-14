#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include <cstddef>
#include <tuple>
#include <vector>

class EntityList
{
private:
	struct Vertex
	{
		sf::CircleShape circle{};
		sf::Text label{};
	};

	struct Edge
	{
		sf::RectangleShape line{};
		std::size_t rowIndex{};
		std::size_t columnIndex{};
	};

public:
	EntityList();

	void pushVertexEntity(sf::CircleShape&& circle, sf::Text&& label);
	void pushEdgeEntity(sf::RectangleShape&& line, std::size_t rowIndex, std::size_t columnIndex);

	void popVertexEntityAtIndex(std::size_t index);
	// change this to find the proper edge by it's indices
	void popEdgeEntityAtIndices(std::size_t rowIndex, std::size_t columnIndex);

	void clearVertexEntities();
	void clearEdgeEntities();

	std::size_t getVertexListSize() const;
	std::size_t getEdgeListSize() const;

	Vertex getVertexEntityAtIndex(std::size_t index) const;
	Edge getEdgeEntityAtIndex(std::size_t index) const;

	void changeVertexEntityColorAtIndex(std::size_t index);

	void reorganizeVertexLabels();

	int getIndexFromLabel(sf::Text& label);

	void draw(sf::RenderWindow& window) const;

private:
	std::vector<Vertex> m_vertexEntities{};
	std::vector<Edge> m_edgeEntities{};

	int m_numberOfChosenVertices{};
};

#endif
