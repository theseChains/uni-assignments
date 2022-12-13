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

		if (MouseInfo::mouseTooCloseToOtherVertex(context.m_entityList, context.m_window))
			return;

		sf::CircleShape vertex{ constants::vertexRadius };
		vertex.setPosition(MouseInfo::getMousePosition(context.m_window) -
				sf::Vector2f{ 15.0f, 15.0f });
		vertex.setFillColor(vertex::color);
		context.m_entityList.pushCircleEntity(std::move(vertex));
	}
};

struct VertexChooser
{
	void operator()(Context context)
	{
		EntityList& entityList{ context.m_entityList };

		for (std::size_t i{ 0 }; i < entityList.getCircleListSize(); ++i)
		{
			sf::FloatRect bounds{ entityList.getCircleEntityAtIndex(i).getGlobalBounds() };
			if (bounds.contains(MouseInfo::getMousePosition(context.m_window)))
			{
				entityList.changeCircleEntityColorAtIndex(i);
			}
		}
	}
};

struct VertexRemover
{
	void operator()(Context context)
	{
		EntityList& entityList{ context.m_entityList };

		for (std::size_t i{ 0 }; i < entityList.getCircleListSize(); ++i)
		{
			sf::FloatRect bounds{ entityList.getCircleEntityAtIndex(i).getGlobalBounds() };
			if (bounds.contains(MouseInfo::getMousePosition(context.m_window)))
			{
				entityList.popCircleEntityAtIndex(i);
			}
		}
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
	m_keyBinding[sf::Keyboard::R] = Action::removeVertex;
}

void UserInput::initializeActionBindings()
{
	m_actionBinding[Action::createVertex] = VertexCreator{};
	m_actionBinding[Action::chooseVertex] = VertexChooser{};
	m_actionBinding[Action::removeVertex] = VertexRemover{};

	m_actionBinding[Action::changeMatrixNumber] = MatrixNumberChanger{};
}
