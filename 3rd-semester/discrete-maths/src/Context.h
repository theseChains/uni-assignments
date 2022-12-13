#ifndef APPLICATION_CONTEXT_H
#define APPLICATION_CONTEXT_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "AdjacencyMatrix.h"
#include "EntityList.h"
#include "FontHolder.h"

struct Context
{
	Context(sf::RenderWindow& window, AdjacencyMatrix& matrix, EntityList& entityList,
			FontHolder& FontHolder)
		: m_window{ window }
		, m_adjacencyMatrix{ matrix }
		, m_entityList{ entityList }
		, m_fontHolder{ FontHolder }
	{
	}

	sf::RenderWindow& m_window;
	AdjacencyMatrix& m_adjacencyMatrix;
	EntityList& m_entityList;
	FontHolder& m_fontHolder;
};

#endif
