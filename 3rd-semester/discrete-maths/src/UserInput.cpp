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
		EntityList& entityList{ context.m_entityList };

		std::size_t numberOfActiveVertices{ entityList.getVertexListSize() };
		auto indicesAndValue{ context.m_adjacencyMatrix.handleLeftMouseClick(context.m_window,
				numberOfActiveVertices) };
		if (indicesAndValue && indicesAndValue->matrixValue)
			makeEdge(indicesAndValue->rowIndex, indicesAndValue->columnIndex, entityList);
		else if (indicesAndValue && !indicesAndValue->matrixValue)
			removeEdge(indicesAndValue->rowIndex, indicesAndValue->columnIndex, entityList);
	}

	void makeEdge(std::size_t rowIndex, std::size_t columnIndex, EntityList& entityList)
	{
		auto firstVertexPosition{
			entityList.getVertexEntityAtIndex(rowIndex).circle.getPosition() };
		auto secondVertexPosition{
			entityList.getVertexEntityAtIndex(columnIndex).circle.getPosition() };

		auto [line, triangle]{ createEdgeShapes(firstVertexPosition, secondVertexPosition) };

		entityList.pushEdgeEntity(std::move(line), std::move(triangle), rowIndex, columnIndex);
	}

	void removeEdge(std::size_t rowIndex, std::size_t columnIndex, EntityList& entityList)
	{
		entityList.popEdgeEntityAtIndices(rowIndex, columnIndex);
	}

	std::pair<sf::RectangleShape, sf::CircleShape> createEdgeShapes(
			const sf::Vector2f& firstVertexPosition, const sf::Vector2f& secondVertexPosition)
	{
		sf::RectangleShape line{
			{ getEdgeLength(firstVertexPosition, secondVertexPosition), 3.0f } };
		sf::CircleShape triangle{ 10.0f, 3 };

		sf::Color edgeColor{ getEdgeColor() };
		float edgeRotationAngle{ getEdgeRotation(firstVertexPosition, secondVertexPosition) };

		line.setPosition(firstVertexPosition + sf::Vector2f{ constants::vertexRadius,
				constants::vertexRadius });
		line.setFillColor(edgeColor);
		line.setRotation(edgeRotationAngle);

		triangle.setFillColor(edgeColor);
		triangle.setRotation(edgeRotationAngle + 90.0f);
		// todo: fix this
		if (firstVertexPosition.x < secondVertexPosition.x)
			triangle.setPosition(secondVertexPosition - sf::Vector2f{ 20.0f, 20.0f });
		else
			triangle.setPosition(secondVertexPosition + sf::Vector2f{ 20.0f, 20.0f });

		return { line, triangle };
	}

	float getEdgeLength(const sf::Vector2f& firstPosition, const sf::Vector2f& secondPosition)
	{
		return (static_cast<float>(std::sqrt(std::pow((secondPosition.x - firstPosition.x), 2) +
				std::pow((secondPosition.y - firstPosition.y), 2))));
	}

	sf::Color getEdgeColor()
	{
		sf::Color color{ rnd::getUchar(0, 200), rnd::getUchar(0, 200), rnd::getUchar(205, 255) };
		return { color };
	}

	float getEdgeRotation(const sf::Vector2f& firstPosition, const sf::Vector2f& secondPosition)
	{
		auto slope{ (firstPosition.y - secondPosition.y) / (firstPosition.x - secondPosition.x) };
		float angle{ static_cast<float>(atan(slope)) * 180.0f / std::numbers::pi_v<float> };
		if (firstPosition.x >= secondPosition.x)
			angle += 180.0f;
		return angle;
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
