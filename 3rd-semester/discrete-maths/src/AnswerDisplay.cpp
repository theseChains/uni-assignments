#include "AnswerDisplay.h"

#include <iomanip>
#include <string>
#include <sstream>

AnswerDisplay::AnswerDisplay() : m_answerText{}, m_font{}
{
	m_answerText.setPosition({ 15.0f, 600.0f });
	m_answerText.setCharacterSize(18);
	m_answerText.setFillColor({ 200, 255, 100 });
}

void AnswerDisplay::setAnswerFont(const sf::Font& font)
{
	m_font = &font;
	m_answerText.setFont(*m_font);
}

void AnswerDisplay::setDistanceAnswer(const std::array<int, 2>& indices, int power)
{
	std::ostringstream stream{};
	stream << "Distance between vertices v" + std::to_string(indices[0]) + " and v" +
			std::to_string(indices[1]) + '\n' << std::setw(35) << "is equal to " +
					std::to_string(power);
	m_answerText.setString(stream.str());
}

void AnswerDisplay::setNumberOfRoutesAnswer(const std::array<int, 2>& indices, int routeDistance,
		int numberOfRoutes)
{
	std::ostringstream stream{};
	stream << std::setw(38) << "Number of routes of distance " << std::to_string(routeDistance) +
			"\nbetween vertices v" + std::to_string(indices[0]) + " and v" +
					std::to_string(indices[1]) + " is equal to " + std::to_string(numberOfRoutes);
	m_answerText.setString(stream.str());
}

void AnswerDisplay::draw(sf::RenderWindow& window) const
{
	window.draw(m_answerText);
}
