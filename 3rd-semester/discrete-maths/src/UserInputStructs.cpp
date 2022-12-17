#include "UserInputStructs.h"
#include "MouseInfo.h"
#include "Constants.h"
#include "Colors.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include <cmath>
#include <memory>
#include <numbers>
#include <string>

void VertexCreator::operator()(Context context)
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

sf::CircleShape VertexCreator::createCircle(sf::RenderWindow& window)
{
	sf::CircleShape circle{ constants::vertexRadius };
	circle.setPosition(MouseInfo::getMousePosition(window) -
			sf::Vector2f{ constants::vertexRadius, constants::vertexRadius });
	circle.setFillColor(color::vertex);

	return circle;
}

sf::Text VertexCreator::createLabel(const EntityList& entityList,
		const FontHolder& fontHolder, const sf::Vector2f& circlePosition)
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

void VertexChooser::operator()(Context context)
{
	EntityList& entityList{ context.m_entityList };

	for (std::size_t vertexIndex{ 0 }; vertexIndex < entityList.getVertexListSize(); ++vertexIndex)
	{
		sf::FloatRect bounds{
			entityList.getVertexEntityAtIndex(vertexIndex).circle.getGlobalBounds() };
		if (bounds.contains(MouseInfo::getMousePosition(context.m_window)))
		{
			entityList.changeVertexEntityColorAtIndex(vertexIndex);
			return;
		}
	}
}

void VertexRemover::operator()(Context context)
{
	EntityList& entityList{ context.m_entityList };
	AdjacencyMatrix& adjacencyMatrix{ context.m_adjacencyMatrix };
	std::size_t numberOfActiveVertices{ entityList.getVertexListSize() };

	for (std::size_t vertexIndex{ 0 }; vertexIndex < numberOfActiveVertices; ++vertexIndex)
	{
		sf::FloatRect bounds{
			entityList.getVertexEntityAtIndex(vertexIndex).circle.getGlobalBounds() };
		if (bounds.contains(MouseInfo::getMousePosition(context.m_window)))
		{
			entityList.popVertexEntityAtIndex(vertexIndex);
			entityList.reorganizeVertexLabels();
			adjacencyMatrix.reorganizeMatrixAfterVertexRemoval(vertexIndex, numberOfActiveVertices);
			entityList.reorganizeEdges(adjacencyMatrix.getMatrix(), numberOfActiveVertices - 1);
			return;
		}
	}
}

void MatrixNumberChanger::operator()(Context context)
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

void MatrixNumberChanger::makeEdge(std::size_t rowIndex, std::size_t columnIndex,
		EntityList& entityList)
{
	auto firstVertexPosition{
		entityList.getVertexEntityAtIndex(rowIndex).circle.getPosition() };
	auto secondVertexPosition{
		entityList.getVertexEntityAtIndex(columnIndex).circle.getPosition() };

	Edge newEdge{ rowIndex, columnIndex, firstVertexPosition, secondVertexPosition };
	Edge newReverseEdge{ columnIndex, rowIndex, firstVertexPosition, secondVertexPosition };

	entityList.pushEdgeEntity(newEdge);
	entityList.pushEdgeEntity(newReverseEdge);
}

void MatrixNumberChanger::removeEdge(std::size_t rowIndex, std::size_t columnIndex,
		EntityList& entityList)
{
	entityList.popEdgeEntityAtIndices(rowIndex, columnIndex);
	entityList.popEdgeEntityAtIndices(columnIndex, rowIndex);
}
