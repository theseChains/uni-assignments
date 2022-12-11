#include "MouseInfo.h"

sf::Vector2f MouseInfo::getMousePosition(sf::RenderWindow& window)
{
	float xMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).x) };
	float yMouseCoordinate{ static_cast<float>(sf::Mouse::getPosition(window).y) };
	return { xMouseCoordinate, yMouseCoordinate };
}
