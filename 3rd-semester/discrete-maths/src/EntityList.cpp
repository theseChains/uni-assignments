#include "EntityList.h"
#include "Colors.h"
#include "Constants.h"

EntityList::EntityList()
	: m_vertexEntities{}
	, m_edgeEntities{}
	, m_numberOfChosenDistanceVertices{ 0 }
	, m_numberOfChosenRouteVertices{ 0 }
{
}

void EntityList::pushVertexEntity(const Vertex& vertex)
{
	m_vertexEntities.push_back(vertex);
}

void EntityList::pushEdgeEntity(const Edge& edge)
{
	m_edgeEntities.push_back(edge);
}

void EntityList::popVertexEntityAtIndex(std::size_t index)
{
	Vertex vertexToDelete{ getVertexEntityAtIndex(index) };
	if (vertexToDelete.getCircleFillColor() == color::chosenVertex)
	{
		--m_numberOfChosenRouteVertices;
		std::erase(m_chosenRouteVertices, vertexToDelete);
	}
	else if (vertexToDelete.getCirclePointCount() == constants::chosenVertexPointCount)
	{
		--m_numberOfChosenDistanceVertices;
		std::erase(m_chosenDistanceVertices, vertexToDelete);
	}
	m_vertexEntities.erase(m_vertexEntities.begin() + index);
}

void EntityList::popEdgeEntityAtIndices(std::size_t rowIndex, std::size_t columnIndex)
{
	std::erase_if(m_edgeEntities, [=](const Edge& edge)
			{
				return (edge.getRow() == rowIndex && edge.getColumn() == columnIndex);
			});
}

void EntityList::clearVertexEntities()
{
	m_vertexEntities.clear();
}

void EntityList::clearEdgeEntities()
{
	m_edgeEntities.clear();
}

std::size_t EntityList::getVertexListSize() const
{
	return m_vertexEntities.size();
}

std::size_t EntityList::getEdgeListSize() const
{
	return m_edgeEntities.size();
}

Vertex& EntityList::getVertexEntityAtIndex(std::size_t index)
{
	return m_vertexEntities.at(index);
}

Edge& EntityList::getEdgeEntityAtIndex(std::size_t index)
{
	return m_edgeEntities.at(index);
}

bool EntityList::allDistanceVerticesAreChosen() const
{
	return m_numberOfChosenDistanceVertices == 2;
}

bool EntityList::allRouteVerticesAreChosen() const
{
	return m_numberOfChosenRouteVertices == 2;
}

std::array<int, 2> EntityList::getChosenRouteVerticesIndices() const
{
	return { m_chosenRouteVertices[0].getIndexFromLabel(),
			 m_chosenRouteVertices[1].getIndexFromLabel() };
}

std::array<int, 2> EntityList::getChosenDistanceVerticesIndices() const
{
	return { m_chosenDistanceVertices[0].getIndexFromLabel(),
			 m_chosenDistanceVertices[1].getIndexFromLabel() };
}

void EntityList::changeVertexEntityColorAtIndex(std::size_t index)
{
	Vertex& chosenVertex{ getVertexEntityAtIndex(index) };
	if (chosenVertex.getCirclePointCount() == constants::chosenVertexPointCount)
		return;

	if (chosenVertex.getCircleFillColor() == color::chosenVertex)
	{
		chosenVertex.setCircleColor(color::vertex);
		chosenVertex.setLabelColor(color::label);
		--m_numberOfChosenRouteVertices;
		std::erase(m_chosenRouteVertices, chosenVertex);
	}
	else if (m_numberOfChosenRouteVertices < 2)
	{
		chosenVertex.setCircleColor(color::chosenVertex);
		chosenVertex.setLabelColor(color::chosenLabel);
		++m_numberOfChosenRouteVertices;
		m_chosenRouteVertices.push_back(chosenVertex);
	}
}

void EntityList::changeVertexEntityPointCount(std::size_t index)
{
	Vertex& chosenVertex{ getVertexEntityAtIndex(index) };
	if (chosenVertex.getCircleFillColor() == color::chosenVertex)
		return;

	if (chosenVertex.getCirclePointCount() == constants::chosenVertexPointCount)
	{
		chosenVertex.setCirclePointCount(constants::defaultVertexPointCount);
		--m_numberOfChosenDistanceVertices;
		std::erase(m_chosenDistanceVertices, chosenVertex);
	}
	else if (m_numberOfChosenDistanceVertices < 2)
	{
		chosenVertex.setCirclePointCount(constants::chosenVertexPointCount);
		++m_numberOfChosenDistanceVertices;
		m_chosenDistanceVertices.push_back(chosenVertex);
	}
}

void EntityList::reorganizeVertexLabels()
{
	for (int vertexIndex{ 0 }; auto& vertex : m_vertexEntities)
	{
		// also the index to string conversion should be encapsulated in the vertex class
		vertex.setLabelText("v" + std::to_string(vertexIndex));

		// update the chosen vertex labels too
		auto chosenDistanceVertex{ std::ranges::find(m_chosenDistanceVertices, vertex) };
		if (chosenDistanceVertex != m_chosenDistanceVertices.end())
			chosenDistanceVertex->setLabelText("v" + std::to_string(vertexIndex));

		auto chosenRouteVertex{ std::ranges::find(m_chosenRouteVertices, vertex) };
		if (chosenRouteVertex != m_chosenRouteVertices.end())
			chosenRouteVertex->setLabelText("v" + std::to_string(vertexIndex));

		++vertexIndex;
	}
}

void EntityList::reorganizeEdges(const Matrix& matrix, std::size_t numberOfActiveVertices)
{
	std::vector<Edge> newEdges{};
	for (std::size_t row{ 0 }; row < numberOfActiveVertices; ++row)
	{
		for (std::size_t column{ row + 1 }; column < numberOfActiveVertices; ++column)
		{
			if (matrix[row,column] == 1)
			{
				auto firstVertexPos{ getVertexEntityAtIndex(row).getCirclePosition() };
				auto secondVertexPos{ getVertexEntityAtIndex(column).getCirclePosition() };
				Edge newEdge{ row, column, firstVertexPos, secondVertexPos };
				newEdges.push_back(newEdge);
			}
		}
	}

	m_edgeEntities = newEdges;
}

void EntityList::draw(sf::RenderWindow& window) const
{
	for (const auto& edge : m_edgeEntities)
	{
		window.draw(edge.getLine());
	}

	for (const auto& vertex : m_vertexEntities)
	{
		window.draw(vertex.getCircle());
		window.draw(vertex.getLabel());
	}
}
