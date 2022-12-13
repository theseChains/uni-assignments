#include "EntityList.h"

EntityList::EntityList() : m_circleEntities{}, m_lineEntities{}, m_numberOfChosenVertices{ 0 }
{
}

void EntityList::pushCircleEntity(sf::CircleShape&& circleEntity)
{
	m_circleEntities.push_back(circleEntity);
}

void EntityList::pushLineEntity(sf::RectangleShape&& lineEntity)
{
	m_lineEntities.push_back(lineEntity);
}

void EntityList::popCircleEntityAtIndex(std::size_t index)
{
	m_circleEntities.erase(m_circleEntities.begin() + index);
}

void EntityList::popLineEntityAtIndex(std::size_t index)
{
	m_lineEntities.erase(m_lineEntities.begin() + index);
}

void EntityList::clearCircleEntities()
{
	m_circleEntities.clear();
}

void EntityList::clearLineEntities()
{
	m_lineEntities.clear();
}

std::size_t EntityList::getCircleListSize() const
{
	return m_circleEntities.size();
}

std::size_t EntityList::getLineListSize() const
{
	return m_lineEntities.size();
}

sf::CircleShape EntityList::getCircleEntityAtIndex(std::size_t index) const
{
	return m_circleEntities.at(index);
}

sf::RectangleShape EntityList::getLineEntityAtIndex(std::size_t index) const
{
	return m_lineEntities.at(index);
}

void EntityList::changeCircleEntityColorAtIndex(std::size_t index)
{
	if (m_circleEntities.at(index).getFillColor() == chosen::color)
	{
		m_circleEntities.at(index).setFillColor(vertex::color);
		--m_numberOfChosenVertices;
	}
	else if (m_numberOfChosenVertices < 2)
	{
		m_circleEntities.at(index).setFillColor(chosen::color);
		++m_numberOfChosenVertices;
	}
}

void EntityList::draw(sf::RenderWindow& window) const
{
	for (const auto& entity : m_circleEntities)
	{
		window.draw(entity);
	}

	for (const auto& entity : m_lineEntities)
	{
		window.draw(entity);
	}
}
