#include "EntityList.h"
#include "Colors.h"

EntityList::EntityList() : m_vertexEntities{}, m_edgeEntities{}, m_numberOfChosenVertices{ 0 }
{
}

void EntityList::pushVertexEntity(sf::CircleShape&& circle, sf::Text&& label)
{
	m_vertexEntities.push_back({ circle, label });
}

void EntityList::pushEdgeEntity(sf::ConvexShape&& edge)
{
	m_edgeEntities.push_back(edge);
}

void EntityList::popVertexEntityAtIndex(std::size_t index)
{
	m_vertexEntities.erase(m_vertexEntities.begin() + index);
}

void EntityList::popEdgeEntityAtIndex(std::size_t index)
{
	m_edgeEntities.erase(m_edgeEntities.begin() + index);
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

sf::ConvexShape EntityList::getEdgeEntityAtIndex(std::size_t index) const
{
	return m_edgeEntities.at(index);
}

void EntityList::changeVertexEntityColorAtIndex(std::size_t index)
{
	if (m_vertexEntities.at(index).circle.getFillColor() == chosen::color)
	{
		m_vertexEntities.at(index).circle.setFillColor(vertex::color);
		--m_numberOfChosenVertices;
	}
	else if (m_numberOfChosenVertices < 2)
	{
		m_vertexEntities.at(index).circle.setFillColor(chosen::color);
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
	for (const auto& vertex : m_vertexEntities)
	{
		window.draw(vertex.circle);
		window.draw(vertex.label);
	}

	for (const auto& edge : m_edgeEntities)
	{
		window.draw(edge);
	}
}
