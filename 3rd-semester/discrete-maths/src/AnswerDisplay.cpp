#include "AnswerDisplay.h"
#include "Colors.h"

#include <iomanip>
#include <string>
#include <sstream>

AnswerDisplay::AnswerDisplay() : m_distanceAnswerText{}, m_numberOfRoutesAnswerText{}, m_font{}
{
	m_distanceAnswerText.setPosition({ 10.0f, 400.0f });
	m_distanceAnswerText.setCharacterSize(18);
	m_distanceAnswerText.setFillColor(color::answerText);
	std::ostringstream distanceStream{};
	distanceStream << "  Specify 2 vertices between which you want\nto find the distance by "
			<< "hovering over a vertex\n" << std::setw(45) << "and pressing D";
	m_distanceAnswerText.setString(distanceStream.str());

	m_numberOfRoutesAnswerText.setPosition({ 10.0f, 600.0f });
	m_numberOfRoutesAnswerText.setCharacterSize(18);
	m_numberOfRoutesAnswerText.setFillColor(color::answerText);
	std::ostringstream routesStream{};
	routesStream << "  Specify 2 vertices between which you want\nto find the number of routes of "
			<< "length (q - p + 3)\n    by hovering over a vertex and pressing N";
	m_numberOfRoutesAnswerText.setString(routesStream.str());
}

void AnswerDisplay::setAnswerFont(const sf::Font& font)
{
	m_font = &font;
	m_distanceAnswerText.setFont(*m_font);
	m_numberOfRoutesAnswerText.setFont(*m_font);
}

void AnswerDisplay::setDistanceAnswer(const std::array<int, 2>& indices, int power)
{
	std::ostringstream stream{};
	stream << std::setw(45) << "Distance between vertices v" + std::to_string(indices[0]) +
			" and v" + std::to_string(indices[1]) + '\n' << std::setw(46) << "is equal to " +
					std::to_string(power);
	m_distanceAnswerText.setString(stream.str());
}

void AnswerDisplay::setNumberOfRoutesAnswer(const std::array<int, 2>& indices, int routeDistance,
		int numberOfRoutes)
{
	std::ostringstream stream{};
	stream << std::setw(45) << "Number of routes of distance " << std::to_string(routeDistance) +
			"\n    between vertices v" + std::to_string(indices[0]) + " and v" +
					std::to_string(indices[1]) + " is equal to " + std::to_string(numberOfRoutes);
	m_numberOfRoutesAnswerText.setString(stream.str());
}

void AnswerDisplay::draw(sf::RenderWindow& window) const
{
	window.draw(m_distanceAnswerText);
	window.draw(m_numberOfRoutesAnswerText);
}
