#ifndef ANSWER_DISPLAY_H
#define ANSWER_DISPLAY_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <array>

class AnswerDisplay
{
public:
	AnswerDisplay();

	void setAnswerFont(const sf::Font& font);
	void setUnreachableAnswer(const std::array<int, 2>& indices);
	void setDistanceAnswer(const std::array<int, 2>& indices, int power);
	void setNumberOfRoutesAnswer(const std::array<int, 2>& indices, int routeDistance,
			int numberOfRoutes);

	void draw(sf::RenderWindow& window) const;

private:
	sf::Text m_distanceAnswerText{};
	sf::Text m_numberOfRoutesAnswerText{};
	const sf::Font* m_font{};
};

#endif
