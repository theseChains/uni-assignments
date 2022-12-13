#include "MouseInfo.h"
#include "Config.h"

sf::Vector2f MouseInfo::getMousePosition(sf::RenderWindow& window)
{
	float xMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).x) };
	float yMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).y) };
	return { xMouseCoordinate, yMouseCoordinate };
}

bool MouseInfo::isMouseOnVertexPlane(sf::RenderWindow& window)
{
	sf::Vector2f mousePos{ getMousePosition(window) };

	return (mousePos.x <= constants::adjacencyMatrixWidth + constants::vertexRadius);
}

bool MouseInfo::mouseTooCloseToOtherVertex(EntityList& entityList, sf::RenderWindow& window)
{
	for (std::size_t i{ 0 }; i < entityList.getCircleListSize(); ++i)
	{
		sf::FloatRect bounds{ entityList.getCircleEntityAtIndex(i).getGlobalBounds() };
		bounds.top -= constants::minimumDistanceBetweenVertices;
		bounds.left -= constants::minimumDistanceBetweenVertices;
		bounds.height += constants::minimumDistanceBetweenVertices * 2;
		bounds.width += constants::minimumDistanceBetweenVertices * 2;

		if (bounds.contains(MouseInfo::getMousePosition(window)))
			return true;
	}

	return false;
}
