#include "AdjacencyMatrix.h"
#include "Config.h"

#include <SFML/Graphics/CircleShape.hpp>

#include <iostream>
#include <string>

AdjacencyMatrix::AdjacencyMatrix() : m_matrix{}
{
	m_font.loadFromFile("../res/FiraMono-Medium.otf");

	initializeTopText();
	initializeMatrixTextCoordinates();
	initializeMatrixText();
}

void AdjacencyMatrix::handleEvent()
{
	// handle clicking on the numbers of the matrix
}

void AdjacencyMatrix::update()
{
	// update the matrix text
}

void AdjacencyMatrix::draw(sf::RenderWindow& window) const
{
	window.draw(m_topText);

	for (const auto& text : m_matrixText)
		window.draw(text);

	for (const auto& row : m_matrixTextCoordinates)
	{
		for (const auto& [x, y] : row)
		{
			sf::CircleShape circle{};
			circle.setPosition(x, y);
			circle.setRadius(7.5f);
			circle.setFillColor(sf::Color{ 200, 200, 255, 180 });
			window.draw(circle);
		}
	}
}

void AdjacencyMatrix::initializeTopText()
{
	m_topText.setFont(m_font);
	m_topText.setString("    Adjacency matrix");
	m_topText.setCharacterSize(25);
	m_topText.setFillColor(sf::Color{ text::red, text::green, text::blue });
}

void AdjacencyMatrix::initializeMatrixTextCoordinates()
{
	int rowIndex{ 1 };
	for (auto& row : m_matrixTextCoordinates)
	{
		int columnIndex{ 1 };
		for (auto& [x, y] : row)
		{
			x = 33 * columnIndex + 19;
			y = 25 * rowIndex + 29;

			++columnIndex;
		}
		++rowIndex;
	}
}

void AdjacencyMatrix::initializeMatrixText()
{
	for (auto& text : m_matrixText)
	{
		text.setFont(m_font);
		text.setCharacterSize(18);
	}

	m_matrixText[0].setString("    v0 v1 v2 v3 v4 v5 v6 v7 v8 v9");
	m_matrixText[0].setPosition(0.0f, 30.0f);

	for (int i{ 1 }; i < m_matrixText.size(); ++i)
	{
		// this is the number string
		std::string matrixRowString{ "   " };
		for (int j{ 0 }; j < 10; ++j)
		{
			matrixRowString += std::to_string(m_matrix[i - 1][j]) + "  ";
		}

		// v1 + row 1 numbers, and so on
		m_matrixText[i].setString("v" + std::to_string(i - 1) + matrixRowString);
		m_matrixText[i].setPosition(0.0f, 25.0f * (i + 1));
	}
}
