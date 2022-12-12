#include "UserInput.h"
#include "MouseInfo.h"
#include "Config.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Mouse.hpp>

struct VertexCreator
{
	void operator()(EntityList& entityList, sf::RenderWindow& window)
	{
		if (MouseInfo::isMouseOnAdjacencyMatrix(window) || entityList.getCircleListSize() == 10)
			return;

		sf::CircleShape vertex{};
		vertex.setPosition(MouseInfo::getMousePosition(window) - sf::Vector2f{ 15.0f, 15.0f });
		vertex.setRadius(15.0f);
		vertex.setFillColor(sf::Color{ vertex::red, vertex::green, vertex::blue });
		entityList.pushCircleEntity(std::move(vertex));
	}
};

struct VertexChooser
{
	void operator()([[maybe_unused]] EntityList& entityList, [[maybe_unused]] sf::RenderWindow& window)
	{
		// alright, i have a different idea now, how about instead of choosing vertices to make
		// connections with them, we make this struct to choose the vertices between which we want
		// to find the desired length.. i think this is a good idea tbh
		// on second thought, i think recoloring the chosen vertices is a better implementation idea
	}
};

// removing on left click won't work here i think, so the idea here will probably be to remove
// upon pressing R on the keyboard or something (and obviously having the mouse on a vertex)
struct VertexRemover
{
	void operator()()
	{

	}
};

UserInput::UserInput()
{
	initializeBindings();
	initializeActionBindings();
}

void UserInput::handleEvent(const sf::Event& event, EntityList& entityList,
		sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		// check for our designated mouse buttons
		auto found{ m_mouseBinding.find(event.mouseButton.button) };
		if (found != m_mouseBinding.end())
		{
			m_actionBinding[found->second](entityList, window);
		}
	}
}

void UserInput::initializeBindings()
{
	m_mouseBinding[sf::Mouse::Left] = Action::createVertex;
	m_mouseBinding[sf::Mouse::Right] = Action::chooseVertex;
}

void UserInput::initializeActionBindings()
{
	m_actionBinding[Action::createVertex] = VertexCreator{};
	m_actionBinding[Action::chooseVertex] = VertexChooser{};
}
