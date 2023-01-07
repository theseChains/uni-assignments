#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "AdjacencyMatrix.h"
#include "Button.h"
#include "Context.h"
#include "EntityList.h"
#include "FontHolder.h"
#include "UserInput.h"

#include <vector>

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
	FontHolder m_fontHolder{};

	AdjacencyMatrix m_adjacencyMatrix;
	EntityList m_entityList{};
	UserInput m_userInput{};
	std::vector<Button> m_buttons{};

	Context m_context;
};

#endif
