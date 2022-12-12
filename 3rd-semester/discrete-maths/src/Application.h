#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "AdjacencyMatrix.h"
#include "Context.h"
#include "EntityList.h"
#include "UserInput.h"

class Application
{
public:
	Application();
	void run();

private:
	void processInput();
	void update(sf::Time deltaTime);
	void render();

private:
	sf::RenderWindow m_window{};
	AdjacencyMatrix m_adjacencyMatrix{};
	EntityList m_entityList{};
	UserInput m_userInput{};

	Context m_context;
};

#endif
