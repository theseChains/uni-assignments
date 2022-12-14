#include "EntityList.h"
#include "Colors.h"

EntityList::EntityList() : m_vertexEntities{}, m_edgeEntities{}, m_numberOfChosenVertices{ 0 }
{
}

void EntityList::pushVertexEntity(sf::CircleShape&& circle, sf::Text&& label)
{
	m_vertexEntities.push_back({ circle, label });
}

void EntityList::pushEdgeEntity(sf::RectangleShape&& line, sf::CircleShape&& triangle,
		std::size_t rowIndex, std::size_t columnIndex)
{
	m_edgeEntities.push_back({ line, triangle, rowIndex, columnIndex });
}

void EntityList::popVertexEntityAtIndex(std::size_t index)
{
	m_vertexEntities.erase(m_vertexEntities.begin() + index);
}

void EntityList::popEdgeEntityAtIndices(std::size_t rowIndex, std::size_t columnIndex)
{
	std::erase_if(m_edgeEntities, [=](const Edge& edge)
			{
				return (edge.rowIndex == rowIndex && edge.columnIndex == columnIndex);
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

EntityList::Vertex EntityList::getVertexEntityAtIndex(std::size_t index) const
{
	return m_vertexEntities.at(index);
}

EntityList::Edge EntityList::getEdgeEntityAtIndex(std::size_t index) const
{
	return m_edgeEntities.at(index);
}

void EntityList::changeVertexEntityColorAtIndex(std::size_t index)
{
	if (m_vertexEntities.at(index).circle.getFillColor() == color::chosenVertex)
	{
		m_vertexEntities.at(index).circle.setFillColor(color::vertex);
		--m_numberOfChosenVertices;
	}
	else if (m_numberOfChosenVertices < 2)
	{
		m_vertexEntities.at(index).circle.setFillColor(color::chosenVertex);
		++m_numberOfChosenVertices;
	}
}

void EntityList::reorganizeVertexLabels()
{
	for (int vertexIndex{ 0 }; auto& vertex : m_vertexEntities)
	{
		vertex.label.setString("v" + std::to_string(vertexIndex++));
	}
}

int EntityList::getIndexFromLabel(sf::Text& label)
{
	// the label is always 2 letters long, so just return the second character converted to int
	return (label.getString()[1] - '0');
}

void EntityList::draw(sf::RenderWindow& window) const
{
	for (const auto& edge : m_edgeEntities)
	{
		window.draw(edge.line);
		window.draw(edge.triangle);
	}

	for (const auto& vertex : m_vertexEntities)
	{
		window.draw(vertex.label);
		window.draw(vertex.circle);
	}
}
