#ifndef MOUSE_INFO_H
#define MOUSE_INFO_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include <cstddef>

#include "EntityList.h"

class MouseInfo
{
public:
	static sf::Vector2f getMousePosition(sf::RenderWindow& window);
	static bool isMouseOnVertexPlane(sf::RenderWindow& window);
	static bool mouseTooCloseToOtherVertex(EntityList& entityList, sf::RenderWindow& window);
};

#endif
