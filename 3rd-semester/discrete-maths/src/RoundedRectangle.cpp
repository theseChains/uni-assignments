#include "RoundedRectangle.h"

#include <cmath>

void RoundedRectangle::setSize(const sf::Vector2f& size)
{
	m_rectangle.setSize({ size.x - size.y, size.y });
	m_leftCircle.setRadius(size.y / 2);
	m_rightCircle.setRadius(size.y / 2);
}

void RoundedRectangle::setPosition(const sf::Vector2f& position)
{
	m_leftCircle.setPosition(position);
	m_rectangle.setPosition({ position.x + m_leftCircle.getRadius(), position.y });
	m_rightCircle.setPosition({ position.x + m_rectangle.getSize().x, position.y });
}

void RoundedRectangle::setFillColor(const sf::Color& color)
{
	m_rectangle.setFillColor(color);
	m_leftCircle.setFillColor(color);
	m_rightCircle.setFillColor(color);
}

bool isMouseOnCircle(const sf::CircleShape& circle, const sf::Vector2f& mousePosition)
{
	float circleRadius{ circle.getRadius() };
	auto circleCenter{ circle.getPosition() + sf::Vector2f{ circleRadius, circleRadius } };

	// distance between the cursor and the circle center
	float distance{ static_cast<float>(std::sqrt(std::pow(mousePosition.x - circleCenter.x, 2) -
				std::pow(mousePosition.y - circleCenter.y, 2))) };

	return distance <= circleRadius;
}

bool RoundedRectangle::isMouseOnShape(const sf::Vector2f& mousePosition) const
{
	auto rectangleBounds{ m_rectangle.getGlobalBounds() };
	if (rectangleBounds.contains(mousePosition))
		return true;

	if (isMouseOnCircle(m_leftCircle, mousePosition))
		return true;

	if (isMouseOnCircle(m_rightCircle, mousePosition))
		return true;

	return false;
}

void RoundedRectangle::draw(sf::RenderWindow& window) const
{
	window.draw(m_leftCircle);
	window.draw(m_rectangle);
	window.draw(m_rightCircle);
}
