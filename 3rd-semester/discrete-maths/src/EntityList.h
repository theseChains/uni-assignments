#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>
#include <cstddef>
#include <vector>

#include "Edge.h"
#include "Matrix.h"
#include "Vertex.h"

class EntityList
{
public:
	EntityList();

	void pushVertexEntity(const Vertex& vertex);
	void pushEdgeEntity(const Edge& edge);

	void popVertexEntityAtIndex(std::size_t index);
	void popEdgeEntityAtIndices(std::size_t rowIndex, std::size_t columnIndex);

	void clearVertexEntities();
	void clearEdgeEntities();

	std::size_t getVertexListSize() const;
	std::size_t getEdgeListSize() const;

	Vertex& getVertexEntityAtIndex(std::size_t index);
	Edge& getEdgeEntityAtIndex(std::size_t index);
	std::array<int, 2> getChosenRouteVerticesIndices() const;
	std::array<int, 2> getChosenDistanceVerticesIndices() const;

	bool allDistanceVerticesAreChosen() const;
	bool allRouteVerticesAreChosen() const;

	void changeVertexEntityColorAtIndex(std::size_t index);
	void changeVertexEntityPointCount(std::size_t index);

	void reorganizeVertexLabels();
	void reorganizeEdges(const Matrix& matrix, std::size_t numberOfActiveVertices);

	void draw(sf::RenderWindow& window) const;

private:
	std::vector<Vertex> m_vertexEntities{};
	std::vector<Edge> m_edgeEntities{};

	std::vector<Vertex> m_chosenDistanceVertices{};
	std::vector<Vertex> m_chosenRouteVertices{};
	int m_numberOfChosenDistanceVertices{};
	int m_numberOfChosenRouteVertices{};
};

#endif
