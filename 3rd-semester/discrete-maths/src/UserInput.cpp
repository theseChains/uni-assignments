#include "UserInput.h"
#include "MouseInfo.h"
#include "Colors.h"
#include "Constants.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

#include <cmath>
#include <memory>
#include <numbers>
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
		circle.setFillColor(color::vertex);

		return circle;
	}

	sf::Text createLabel(const EntityList& entityList, const FontHolder& fontHolder,
			const sf::Vector2f& circlePosition)
	{
		sf::Text label{};
		label.setFont(fontHolder.getFont(Fonts::ID::mono));
		label.setFillColor(color::label);
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
				entityList.reorganizeVertexLabels();
			}
		}
	}
};

struct MatrixNumberChanger
{
	void operator()(Context context)
	{
		std::size_t numberOfActiveVertices{ context.m_entityList.getVertexListSize() };
		auto vertexIndices{ context.m_adjacencyMatrix.handleLeftMouseClick(context.m_window,
				numberOfActiveVertices) };
		if (vertexIndices)
			makeEdge(*vertexIndices, context.m_entityList);
	}

	void makeEdge(std::pair<int, int>& vertexIndices, EntityList& entityList)
	{
		auto firstVertexPosition{
			entityList.getVertexEntityAtIndex(vertexIndices.first).circle.getPosition() };
		auto secondVertexPosition{
			entityList.getVertexEntityAtIndex(vertexIndices.second).circle.getPosition() };

		sf::RectangleShape edge{};
		float edgeLength{ static_cast<float>(std::sqrt(std::pow((secondVertexPosition.x -
			firstVertexPosition.x), 2) + std::pow((secondVertexPosition.y -
				firstVertexPosition.y), 2))) };
		edge.setSize({ edgeLength, 3.0f });
		edge.setPosition(firstVertexPosition + sf::Vector2f{ constants::vertexRadius,
				constants::vertexRadius });

		auto slope{ (firstVertexPosition.y - secondVertexPosition.y) /
				(firstVertexPosition.x - secondVertexPosition.x) };
		edge.setRotation(static_cast<float>(atan(slope)) * 180.0f / std::numbers::pi_v<float>);

		if (firstVertexPosition.x >= secondVertexPosition.x)
			edge.rotate(180.0f);

		entityList.pushEdgeEntity(std::move(edge));
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
