#include "UserInput.h"
#include "MouseInfo.h"
#include "Config.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Mouse.hpp>

struct VertexCreator
{
	void operator()(Context context)
	{
		if (MouseInfo::isMouseOnVertexPlane(context.m_window) ||
				context.m_entityList.getCircleListSize() == 10)
			return;

		sf::CircleShape vertex{ 15.0f };
		vertex.setPosition(MouseInfo::getMousePosition(context.m_window) -
				sf::Vector2f{ 15.0f, 15.0f });
		vertex.setFillColor(sf::Color{ color::vertex::red, color::vertex::green, color::vertex::blue });
		context.m_entityList.pushCircleEntity(std::move(vertex));
	}
};

struct VertexChooser
{
	void operator()([[maybe_unused]] Context context)
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
	void operator()([[maybe_unused]] Context context)
	{

	}
};

struct MatrixNumberChanger
{
	void operator()(Context context)
	{
		context.m_adjacencyMatrix.handleLeftMouseClick(context.m_window);
	}
};

UserInput::UserInput()
{
	initializeBindings();
	initializeActionBindings();
}

void UserInput::handleEvent(const sf::Event& event, Context context)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		// check for our designated mouse buttons
		auto found{ m_mouseBinding.find(event.mouseButton.button) };
		if (found != m_mouseBinding.end())
		{
			m_actionBinding[found->second](context);
		}
	}
	else if (event.type == sf::Event::KeyPressed)
	{
		auto found{ m_keyBinding.find(event.key.code) };
		if (found != m_keyBinding.end())
		{
			m_actionBinding[found->second](context);
		}
	}
}

void UserInput::initializeBindings()
{
	m_mouseBinding[sf::Mouse::Left] = Action::changeMatrixNumber;
	m_mouseBinding[sf::Mouse::Right] = Action::chooseVertex;

	m_keyBinding[sf::Keyboard::C] = Action::createVertex;
}

void UserInput::initializeActionBindings()
{
	m_actionBinding[Action::createVertex] = VertexCreator{};
	m_actionBinding[Action::chooseVertex] = VertexChooser{};

	m_actionBinding[Action::changeMatrixNumber] = MatrixNumberChanger{};
}
