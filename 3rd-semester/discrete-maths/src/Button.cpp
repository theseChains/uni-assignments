#include "Button.h"
#include "MouseInfo.h"
#include "Colors.h"

Button::Button(const std::string& text, const sf::Vector2f& position, const sf::Font& font)
{
	m_button.setSize({ 150.0f, 50.0f });
	m_button.setFillColor(color::button);
	m_button.setPosition(position);

	m_text.setFont(font);
	m_text.setString(text);
	m_text.setCharacterSize(18);
	float textHeight{ m_text.getGlobalBounds().height };
	m_text.setPosition(position + sf::Vector2f{ 30.0f, (50.0f - textHeight) / 2.0f - 5.0f });
	m_text.setFillColor(color::buttonText);
}

bool Button::isMouseOnButton(sf::RenderWindow& window) const
{
	return m_button.isMouseOnShape(MouseInfo::getMousePosition(window));
}

bool Button::isClicked(const sf::Event& event, sf::RenderWindow& window) const
{
	return (event.type == sf::Event::MouseButtonPressed && isMouseOnButton(window));
}

void Button::draw(sf::RenderWindow& window) const
{
	m_button.draw(window);
	window.draw(m_text);
}

bool Button::operator<(const Button& other) const
{
	// implemented just so that i can put it into an std::map... is this bad design?
	return m_text.getString().getSize() < other.m_text.getString().getSize();
}
