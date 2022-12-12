#include "EntityList.h"

EntityList::EntityList() : m_circleEntities{}, m_lineEntities{}
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

void EntityList::popCircleEntity()
{
	m_circleEntities.pop_back();
}

void EntityList::popLineEntity()
{
	m_lineEntities.pop_back();
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
