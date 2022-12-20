#include "UserInputStructs.h"
#include "MouseInfo.h"
#include "Constants.h"
#include "Colors.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

void VertexCreator::operator()(Context context)
{
	sf::RenderWindow& window{ context.m_window };
	EntityList& entityList{ context.m_entityList };
	FontHolder& fontHolder{ context.m_fontHolder };

	if (MouseInfo::mouseIsNotOnVertexPlane(window))
		return;

	if (MouseInfo::mouseTooCloseToOtherVertex(entityList, window))
		return;

	if (entityList.getVertexListSize() == constants::maxNumberOfVertices)
		return;

	Vertex newVertex{ MouseInfo::getMousePosition(window), fontHolder.getFont(Fonts::ID::mono),
		entityList.getVertexListSize() };

	entityList.pushVertexEntity(newVertex);
}

void VertexChooserForRoutes::operator()(Context context)
{
	EntityList& entityList{ context.m_entityList };

	for (std::size_t vertexIndex{ 0 }; vertexIndex < entityList.getVertexListSize(); ++vertexIndex)
	{
		sf::FloatRect bounds{
			entityList.getVertexEntityAtIndex(vertexIndex).getCircleGlobalBounds() };
		if (bounds.contains(MouseInfo::getMousePosition(context.m_window)))
		{
			entityList.changeVertexEntityColorAtIndex(vertexIndex);
			return;
		}
	}
}

void VertexChooserForDistance::operator()(Context context)
{
	EntityList& entityList{ context.m_entityList };

	for (std::size_t vertexIndex{ 0 }; vertexIndex < entityList.getVertexListSize(); ++vertexIndex)
	{
		sf::FloatRect bounds{
			entityList.getVertexEntityAtIndex(vertexIndex).getCircleGlobalBounds() };
		if (bounds.contains(MouseInfo::getMousePosition(context.m_window)))
		{
			entityList.changeVertexEntityPointCount(vertexIndex);
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
			entityList.getVertexEntityAtIndex(vertexIndex).getCircleGlobalBounds() };
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
	auto firstVertexPosition{ entityList.getVertexEntityAtIndex(rowIndex).getCirclePosition() };
	auto secondVertexPosition{ entityList.getVertexEntityAtIndex(columnIndex).getCirclePosition() };

	Edge newEdge{ rowIndex, columnIndex, firstVertexPosition, secondVertexPosition };

	entityList.pushEdgeEntity(newEdge);
}

void MatrixNumberChanger::removeEdge(std::size_t rowIndex, std::size_t columnIndex,
		EntityList& entityList)
{
	entityList.popEdgeEntityAtIndices(rowIndex, columnIndex);
	entityList.popEdgeEntityAtIndices(columnIndex, rowIndex);
}
