#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

class EntityList
{
public:
	EntityList();

	void pushCircleEntity(sf::CircleShape&& circleEntity);
	void pushLineEntity(sf::RectangleShape&& lineEntity);

	void popCircleEntity();
	void popLineEntity();

	void clearCircleEntities();
	void clearLineEntities();

	std::size_t getCircleListSize() const;
	std::size_t getLineListSize() const;

	void draw(sf::RenderWindow& window) const;

private:
	std::vector<sf::CircleShape> m_circleEntities{};
	std::vector<sf::RectangleShape> m_lineEntities{};
};

#endif
