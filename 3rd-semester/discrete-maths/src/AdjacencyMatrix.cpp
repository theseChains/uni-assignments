#include "AdjacencyMatrix.h"
#include "Colors.h"
#include "Constants.h"
#include "MouseInfo.h"

#include <SFML/Graphics/CircleShape.hpp>

#include <iostream>
#include <string>

AdjacencyMatrix::AdjacencyMatrix()
	: m_matrix{}
	, m_font{}
	, m_topText{}
	, m_matrixText{}
	, m_matrixNumberBounds{}
{
	m_font.loadFromFile("../res/FiraMono-Medium.otf");

	initializeTopText();
	initializeMatrixTextCoordinates();
	initializeMatrixText();
	initializeMatrixNumberBounds();
	initializeBorderLines();
}

std::optional<std::pair<int, int>> AdjacencyMatrix::handleLeftMouseClick(sf::RenderWindow& window,
		std::size_t numberOfActiveVertices)
{
	for (std::size_t rowIndex{ 0 }; const auto& row : m_matrixNumberBounds)
	{
		for (std::size_t columnIndex{ 0 }; const auto& bound : row)
		{
			if (bound.contains(MouseInfo::getMousePosition(window)) &&
					rowIndex < numberOfActiveVertices && columnIndex < numberOfActiveVertices)
			{
				m_matrix[rowIndex][columnIndex] = !m_matrix[rowIndex][columnIndex];
				return std::pair{ rowIndex, columnIndex };
			}
			++columnIndex;
		}
		++rowIndex;
	}

	return std::nullopt;
}

void AdjacencyMatrix::update()
{
	for (std::size_t i{ 1 }; i < m_matrixText.size(); ++i)
	{
		std::string matrixRowString{ getNumbersFromMatrix(i) };

		m_matrixText[i].setString("v" + std::to_string(i - 1) + matrixRowString);
	}
}

void AdjacencyMatrix::draw(sf::RenderWindow& window) const
{
	window.draw(m_topText);

	for (const auto& text : m_matrixText)
		window.draw(text);

	for (const auto& line : m_borderLines)
		window.draw(line);
}

void AdjacencyMatrix::initializeTopText()
{
	m_topText.setFont(m_font);
	m_topText.setString("Adjacency matrix");
	m_topText.setPosition(70.0f, 0.0f);
	m_topText.setCharacterSize(25);
	m_topText.setFillColor(text::color);
}

void AdjacencyMatrix::initializeMatrixTextCoordinates()
{
	int rowIndex{ 1 };
	for (auto& row : m_matrixTextCoordinates)
	{
		int columnIndex{ 1 };
		for (auto& [x, y] : row)
		{
			x = coords::columnOffsetBetweenValues * static_cast<float>(columnIndex) +
				coords::columnScreenOffset;
			y = coords::rowOffsetBetweenValues * static_cast<float>(rowIndex) +
				coords::rowScreenOffset;

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

	m_matrixText[0].setString("v0 v1 v2 v3 v4 v5 v6 v7 v8 v9");
	m_matrixText[0].setPosition(50.0f, 30.0f);

	for (std::size_t i{ 1 }; i < m_matrixText.size(); ++i)
	{
		std::string matrixRowString{ getNumbersFromMatrix(i) };

		// v1 + row 1 numbers, and so on
		m_matrixText[i].setString("v" + std::to_string(i - 1) + matrixRowString);
		m_matrixText[i].setPosition(0.0f, 25.0f * (static_cast<float>(i + 1)));
	}
}

void AdjacencyMatrix::initializeMatrixNumberBounds()
{
	for (int rowIndex{ 0 }; auto& row : m_matrixNumberBounds)
	{
		for (int columnIndex{ 0 }; auto& numberBound : row)
		{
			sf::FloatRect bound{ { m_matrixTextCoordinates[rowIndex][columnIndex].first,
				m_matrixTextCoordinates[rowIndex][columnIndex].second }, { 15.0f, 15.0f } };
			numberBound = bound;
			++columnIndex;
		}
		++rowIndex;
	}
}

void AdjacencyMatrix::initializeBorderLines()
{
	sf::RectangleShape verticalLine{ { 2.0f, constants::windowWidth } };
	verticalLine.setFillColor(line::color);
	verticalLine.setPosition({ constants::adjacencyMatrixWidth, 0.0f });

	sf::RectangleShape horizontalLine{ { constants::adjacencyMatrixWidth, 2.0f } };
	horizontalLine.setFillColor(line::color);
	horizontalLine.setPosition({ 0.0f, constants::adjacencyMatrixHeight });

	m_borderLines[0] = verticalLine;
	m_borderLines[1] = horizontalLine;
}

std::string AdjacencyMatrix::getNumbersFromMatrix(std::size_t row)
{
	std::string matrixRowString{ "   " };
	for (std::size_t j{ 0 }; j < 10; ++j)
	{
		// retreive numbers from the string
		matrixRowString += std::to_string(m_matrix[row - 1][j]) + "  ";
	}

	return matrixRowString;
}
