#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

#include <string>

class Button
{
public:
	Button(const std::string& text, const sf::Vector2f& position, const sf::Font& font);

	bool isMouseOnButton(sf::RenderWindow& window) const;
	bool isClicked(const sf::Event& event, sf::RenderWindow& window) const;

	void draw(sf::RenderWindow& window) const;

	bool operator<(const Button& other) const;

private:
	sf::RectangleShape m_button{};
	sf::Text m_text{};
};

#endif
