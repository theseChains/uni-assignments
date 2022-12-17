#include "EntityList.h"
#include "Colors.h"

#include <array>

EntityList::EntityList() : m_vertexEntities{}, m_edgeEntities{}, m_numberOfChosenVertices{ 0 }
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

Vertex EntityList::getVertexEntityAtIndex(std::size_t index) const
{
	return m_vertexEntities.at(index);
}

Edge EntityList::getEdgeEntityAtIndex(std::size_t index) const
{
	return m_edgeEntities.at(index);
}

void EntityList::changeVertexEntityColorAtIndex(std::size_t index)
{
	if (m_vertexEntities.at(index).getCircle().getFillColor() == color::chosenVertex)
	{
		m_vertexEntities.at(index).setCircleColor(color::vertex);
		m_vertexEntities.at(index).setLabelColor(color::label);
		--m_numberOfChosenVertices;
	}
	else if (m_numberOfChosenVertices < 2)
	{
		m_vertexEntities.at(index).setCircleColor(color::chosenVertex);
		m_vertexEntities.at(index).setLabelColor(color::chosenLabel);
		++m_numberOfChosenVertices;
	}
}

void EntityList::reorganizeVertexLabels()
{
	for (int vertexIndex{ 0 }; auto& vertex : m_vertexEntities)
	{
		vertex.getLabel().setString("v" + std::to_string(vertexIndex++));
	}
}

void EntityList::reorganizeEdges(const std::array<std::array<bool, 10>, 10>& matrix,
		std::size_t numberOfActiveVertices)
{
	std::vector<Edge> newEdges{};
	for (std::size_t row{ 0 }; row < numberOfActiveVertices; ++row)
	{
		for (std::size_t column{ row + 1 }; column < numberOfActiveVertices; ++column)
		{
			if (matrix[row][column] == 1)
			{
				auto firstVertexPos{ getVertexEntityAtIndex(row).getCircle().getPosition() };
				auto secondVertexPos{ getVertexEntityAtIndex(column).getCircle().getPosition() };
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
