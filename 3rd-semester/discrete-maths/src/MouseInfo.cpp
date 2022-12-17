#include "MouseInfo.h"
#include "Constants.h"

sf::Vector2f MouseInfo::getMousePosition(sf::RenderWindow& window)
{
	float xMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).x) };
	float yMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).y) };
	return { xMouseCoordinate, yMouseCoordinate };
}

bool MouseInfo::mouseIsNotOnVertexPlane(sf::RenderWindow& window)
{
	sf::Vector2f mousePos{ getMousePosition(window) };

	return (mousePos.x <= constants::adjacencyMatrixWidth + constants::vertexRadius +
			constants::labelOffset);
}

bool MouseInfo::mouseTooCloseToOtherVertex(EntityList& entityList, sf::RenderWindow& window)
{
	for (std::size_t i{ 0 }; i < entityList.getVertexListSize(); ++i)
	{
		sf::FloatRect bounds{ entityList.getVertexEntityAtIndex(i).getCircle().getGlobalBounds() };
		bounds.top -= constants::minimumDistanceBetweenVertices;
		bounds.left -= constants::minimumDistanceBetweenVertices;
		bounds.height += constants::minimumDistanceBetweenVertices * 2;
		bounds.width += constants::minimumDistanceBetweenVertices * 2;

		if (bounds.contains(MouseInfo::getMousePosition(window)))
			return true;
	}

	return false;
}
