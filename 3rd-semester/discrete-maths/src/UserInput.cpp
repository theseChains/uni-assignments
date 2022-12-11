#include "UserInput.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Mouse.hpp>

struct VertexCreator
{
	void operator()(EntityList& entityList, sf::RenderWindow& window)
	{
		sf::CircleShape vertex{};
		float xMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).x) };
		float yMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).y) };
		vertex.setPosition(xMouseCoordinate - 15.0f, yMouseCoordinate - 15.0f);
		vertex.setRadius(15.0f);
		vertex.setFillColor(sf::Color{ 240, 240, 250 });
		entityList.pushCircleEntity(std::move(vertex));
	}
};

struct VertexChooser
{
	void operator()(EntityList& entityList)
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
			// this works, lets go
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
	m_actionBinding[Action::createVertex] = VertexCreator();
}
