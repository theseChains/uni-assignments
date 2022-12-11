#include "UserInput.h"
#include "MouseInfo.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Mouse.hpp>

struct VertexCreator
{
	void operator()(EntityList& entityList, sf::RenderWindow& window)
	{
		sf::CircleShape vertex{};
		vertex.setPosition(MouseInfo::getMousePosition(window) - sf::Vector2f{ 15.0f, 15.0f });
		vertex.setRadius(15.0f);
		vertex.setFillColor(sf::Color{ 210, 210, 250 });
		entityList.pushCircleEntity(std::move(vertex));
	}
};

struct VertexChooser
{
	void operator()(EntityList& entityList, sf::RenderWindow& window)
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
	m_actionBinding[Action::createVertex] = VertexCreator{};
	m_actionBinding[Action::chooseVertex] = VertexChooser{};
}
