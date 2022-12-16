#ifndef USER_INPUT_STRUCTS_H
#define USER_INPUT_STRUCTS_H

#include "Context.h"

struct VertexCreator
{
	void operator()(Context context);

	sf::CircleShape createCircle(sf::RenderWindow& window);
	sf::Text createLabel(const EntityList& entityList, const FontHolder& fontHolder,
			const sf::Vector2f& circlePosition);
};

struct VertexChooser
{
	void operator()(Context context);
};

struct VertexRemover
{
	void operator()(Context context);
};

struct MatrixNumberChanger
{
	void operator()(Context context);

	void makeEdge(std::size_t rowIndex, std::size_t columnIndex, EntityList& entityList);
	void removeEdge(std::size_t rowIndex, std::size_t columnIndex, EntityList& entityList);
	sf::RectangleShape createEdgeShape(const sf::Vector2f& firstVertexPosition,
			const sf::Vector2f& secondVertexPosition);
	float getEdgeLength(const sf::Vector2f& firstPosition, const sf::Vector2f& secondPosotion);
	sf::Color getEdgeColor();
	float getEdgeRotation(const sf::Vector2f& firstPosition, const sf::Vector2f& secondPosotion);
};

#endif
