#ifndef MOUSE_INFO_H
#define MOUSE_INFO_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

class MouseInfo
{
public:
	static sf::Vector2f getMousePosition(sf::RenderWindow& window);
	static bool isMouseOnAdjacencyMatrix(sf::RenderWindow& window);
};

#endif
