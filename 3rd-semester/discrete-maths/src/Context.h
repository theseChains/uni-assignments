#ifndef APPLICATION_CONTEXT_H
#define APPLICATION_CONTEXT_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "AdjacencyMatrix.h"
#include "EntityList.h"

struct Context
{
	Context(sf::RenderWindow& window, AdjacencyMatrix& matrix, EntityList& entityList)
		: m_window{ window }, m_adjacencyMatrix{ matrix }, m_entityList{ entityList }
	{
	}

	sf::RenderWindow& m_window;
	AdjacencyMatrix& m_adjacencyMatrix;
	EntityList& m_entityList;
};

#endif
