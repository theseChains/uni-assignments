#include "UserInput.h"
#include "MouseInfo.h"
#include "Colors.h"
#include "Constants.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

#include <memory>
#include <string>

struct VertexCreator
{
	void operator()(Context context)
	{
		if (MouseInfo::mouseIsNotOnVertexPlane(context.m_window) ||
				context.m_entityList.getVertexListSize() == constants::maxNumberOfVertices)
			return;

		if (MouseInfo::mouseTooCloseToOtherVertex(context.m_entityList, context.m_window))
			return;

		sf::CircleShape circle{ createCircle(context.m_window) };
		sf::Text label{ createLabel(context.m_entityList, context.m_fontHolder,
				circle.getPosition()) };
		context.m_entityList.pushVertexEntity(std::move(circle), std::move(label));
	}

	sf::CircleShape createCircle(sf::RenderWindow& window)
	{
		sf::CircleShape circle{ constants::vertexRadius };
		circle.setPosition(MouseInfo::getMousePosition(window) -
				sf::Vector2f{ constants::vertexRadius, constants::vertexRadius });
		circle.setFillColor(vertex::color);

		return circle;
	}

	sf::Text createLabel(const EntityList& entityList, const FontHolder& fontHolder,
			const sf::Vector2f& circlePosition)
	{
		sf::Text label{};
		label.setFont(fontHolder.getFont(Fonts::ID::mono));
		label.setFillColor(label::color);
		label.setString("v" + std::to_string(entityList.getVertexListSize()));
		label.setCharacterSize(18);
		label.setPosition(circlePosition - sf::Vector2f{ constants::labelOffset,
				-constants::vertexRadius / 2 });

		return label;
	}
};

struct VertexChooser
{
	void operator()(Context context)
	{
		EntityList& entityList{ context.m_entityList };

		for (std::size_t i{ 0 }; i < entityList.getVertexListSize(); ++i)
		{
			sf::FloatRect bounds{ entityList.getVertexEntityAtIndex(i).circle.getGlobalBounds() };
			if (bounds.contains(MouseInfo::getMousePosition(context.m_window)))
			{
				entityList.changeVertexEntityColorAtIndex(i);
			}
		}
	}
};

struct VertexRemover
{
	void operator()(Context context)
	{
		EntityList& entityList{ context.m_entityList };

		for (std::size_t i{ 0 }; i < entityList.getVertexListSize(); ++i)
		{
			sf::FloatRect bounds{ entityList.getVertexEntityAtIndex(i).circle.getGlobalBounds() };
			if (bounds.contains(MouseInfo::getMousePosition(context.m_window)))
			{
				entityList.popVertexEntityAtIndex(i);
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
