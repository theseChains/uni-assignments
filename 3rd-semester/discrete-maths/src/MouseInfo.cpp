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

bool MouseInfo::mouseTooCloseToOtherVertex(EntityList& entityList, sf::RenderWindow& window)
{
	for (std::size_t i{ 0 }; i < entityList.getCircleListSize(); ++i)
	{
		sf::FloatRect bounds{ entityList.getCircleEntityAtIndex(i).getGlobalBounds() };
		bounds.top -= 20.0f;
		bounds.left -= 20.0f;
		bounds.height += 40.0f;
		bounds.width += 40.0f;

		if (bounds.contains(MouseInfo::getMousePosition(window)))
			return true;
	}

	return false;
}
