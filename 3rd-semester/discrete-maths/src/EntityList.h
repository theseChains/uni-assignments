#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include <cstddef>
#include <tuple>
#include <vector>

#include "Config.h"

class EntityList
{
private:
	struct Vertex
	{
		sf::CircleShape circle{};
		sf::Text label{};
	};

public:
	EntityList();

	void pushVertexEntity(sf::CircleShape&& circle, sf::Text& label);
	void pushEdgeEntity(sf::RectangleShape&& edge);

	void popVertexEntityAtIndex(std::size_t index);
	void popEdgeEntityAtIndex(std::size_t index);

	void clearVertexEntities();
	void clearEdgeEntities();

	std::size_t getVertexListSize() const;
	std::size_t getEdgeListSize() const;

	Vertex getVertexEntityAtIndex(std::size_t index) const;
	sf::RectangleShape getEdgeEntityAtIndex(std::size_t index) const;

	void changeVertexEntityColorAtIndex(std::size_t index);

	void draw(sf::RenderWindow& window) const;

private:
	std::vector<Vertex> m_vertexEntities{};
	std::vector<sf::RectangleShape> m_edgeEntities{};

	int m_numberOfChosenVertices{};
};

#endif
