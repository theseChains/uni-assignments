#include "UserInputStructs.h"
#include "MouseInfo.h"
#include "Constants.h"
#include "Colors.h"
#include "MatrixOperations.h"

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
			// reorganize edges with one of the vertices gone
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
}

void DistanceSolver::operator()(Context context)
{
	EntityList& entityList{ context.m_entityList };
	if (!entityList.allDistanceVerticesAreChosen())
		return;

	std::array<int, 2> indices{ entityList.getChosenDistanceVerticesIndices() };
	Matrix matrix{ context.m_adjacencyMatrix.getMatrix() };
	int power{ 1 };
	AnswerDisplay& answerDisplay{ context.m_answerDisplay };
	// could also just initialize this with matrix and get the old code back, but whatever
	Matrix matrixRaisedToPower{};
	while (!matrixRaisedToPower[indices[0],indices[1]])
	{
		matrixRaisedToPower = MatrixOperations::getMatrixRaisedToPower(matrix, power);
		++power;
		// the vertex cannot be reached by that point
		if (power > entityList.getVertexListSize() - 1)
		{
			answerDisplay.setUnreachableAnswer(indices);
			return;
		}
	}
	answerDisplay.setDistanceAnswer(indices, power - 1);
}

void NumberOfRoutesSolver::operator()(Context context)
{
	EntityList& entityList{ context.m_entityList };
	if (!entityList.allRouteVerticesAreChosen())
		return;

	Matrix matrix{ context.m_adjacencyMatrix.getMatrix() };
	std::size_t numberOfVertices{ entityList.getVertexListSize() };
	std::size_t numberOfEdges{ entityList.getEdgeListSize() };
	int routeDistance{ static_cast<int>(numberOfEdges - numberOfVertices + 3) };

	matrix = MatrixOperations::getMatrixRaisedToPower(matrix, routeDistance);
	std::array<int, 2> indices{ entityList.getChosenRouteVerticesIndices() };
	context.m_answerDisplay.setNumberOfRoutesAnswer(indices, routeDistance,
			matrix[indices[0],indices[1]]);
}
