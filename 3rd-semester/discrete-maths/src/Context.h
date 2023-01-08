#ifndef APPLICATION_CONTEXT_H
#define APPLICATION_CONTEXT_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "AdjacencyMatrix.h"
#include "AnswerDisplay.h"
#include "EntityList.h"
#include "FontHolder.h"

struct Context
{
	Context(sf::RenderWindow& window, AdjacencyMatrix& matrix, EntityList& entityList,
			FontHolder& fontHolder, AnswerDisplay& answerDisplay)
		: m_window{ window }
		, m_adjacencyMatrix{ matrix }
		, m_entityList{ entityList }
		, m_fontHolder{ fontHolder }
		, m_answerDisplay{ answerDisplay }
	{
	}

	sf::RenderWindow& m_window;
	AdjacencyMatrix& m_adjacencyMatrix;
	EntityList& m_entityList;
	FontHolder& m_fontHolder;
	AnswerDisplay& m_answerDisplay;
};

#endif
