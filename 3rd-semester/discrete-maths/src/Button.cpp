#include "Button.h"
#include "MouseInfo.h"

#include <iostream>

Button::Button(const std::string& text, const sf::Vector2f& position, const sf::Font& font)
{
	m_button.setSize({ 150.0f, 50.0f });
	m_button.setFillColor({ 100, 100, 100 });
	m_button.setPosition(position);

	m_text.setFont(font);
	m_text.setString(text);
	m_text.setCharacterSize(18);
	m_text.setPosition(position + sf::Vector2f{ 35.0f, 15.0f });
	m_text.setFillColor({ 200, 255, 100 });
}

bool Button::isMouseOnButton(sf::RenderWindow& window) const
{
	auto buttonBounds{ m_button.getGlobalBounds() };
	auto mousePosition{ MouseInfo::getMousePosition(window) };

	return buttonBounds.contains(mousePosition);
}

bool Button::isClicked(const sf::Event& event, sf::RenderWindow& window) const
{
	return (event.type == sf::Event::MouseButtonPressed && isMouseOnButton(window));
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_button);
	window.draw(m_text);
}

bool Button::operator<(const Button& other) const
{
	// implemented just so that i can put it into an std::map... is this bad design?
	return m_text.getString().getSize() < other.m_text.getString().getSize();
}
