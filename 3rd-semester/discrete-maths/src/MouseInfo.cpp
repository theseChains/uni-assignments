#include "MouseInfo.h"
#include "Constants.h"

sf::Vector2f MouseInfo::getMousePosition(sf::RenderWindow& window)
{
	// what's the point of this..?
	float xMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).x) };
	float yMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).y) };
	return { xMouseCoordinate, yMouseCoordinate };
}

bool MouseInfo::mouseIsNotOnVertexPlane(sf::RenderWindow& window)
{
	sf::Vector2f mousePos{ getMousePosition(window) };
	auto left{ constants::adjacencyMatrixWidth + constants::vertexRadius };
	auto top{ constants::vertexRadius };
	auto width{ constants::windowWidth - left  - constants::vertexRadius };
	auto height{ constants::windowHeight - top * 2 };
	sf::FloatRect bounds{ left, top, width, height };

	return !bounds.contains(mousePos);
}

bool MouseInfo::mouseTooCloseToOtherVertex(EntityList& entityList, sf::RenderWindow& window)
{
	for (std::size_t i{ 0 }; i < entityList.getVertexListSize(); ++i)
	{
		sf::FloatRect bounds{ entityList.getVertexEntityAtIndex(i).getCircleGlobalBounds() };
		bounds.top -= constants::minimumDistanceBetweenVertices;
		bounds.left -= constants::minimumDistanceBetweenVertices;
		bounds.height += constants::minimumDistanceBetweenVertices * 2;
		bounds.width += constants::minimumDistanceBetweenVertices * 2;

		if (bounds.contains(MouseInfo::getMousePosition(window)))
			return true;
	}

	return false;
}
