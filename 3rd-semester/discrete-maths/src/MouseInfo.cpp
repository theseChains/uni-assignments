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

	return (mousePos.x <= constants::adjacencyMatrixWidth + 15.0f);
}
