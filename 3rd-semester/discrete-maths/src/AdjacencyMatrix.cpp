#include "AdjacencyMatrix.h"
#include "Colors.h"
#include "Constants.h"
#include "MouseInfo.h"

#include <SFML/Graphics/CircleShape.hpp>

#include <ranges>
#include <string>

AdjacencyMatrix::AdjacencyMatrix()
	: m_matrix{}
	, m_mainFont{}
	, m_topText{}
	, m_matrixText{}
	, m_matrixNumberBounds{}
{
	initializeMatrixTextCoordinates();
	initializeMatrixNumberBounds();
	initializeBorderLines();
}

std::optional<AdjacencyMatrix::IndicesAndValue>
AdjacencyMatrix::handleLeftMouseClick(sf::RenderWindow& window, std::size_t numberOfActiveVertices)
{
	for (std::size_t rowIndex{ 0 }; const auto& row : m_matrixNumberBounds)
	{
		for (std::size_t columnIndex{ 0 }; const auto& bound : row)
		{
			if (bound.contains(MouseInfo::getMousePosition(window)) &&
				rowIndex < numberOfActiveVertices && columnIndex < numberOfActiveVertices)
			{
				m_matrix[rowIndex,columnIndex] = !m_matrix[rowIndex,columnIndex];
				m_matrix[columnIndex,rowIndex] = !m_matrix[columnIndex,rowIndex];
				return IndicesAndValue{ rowIndex, columnIndex, m_matrix[rowIndex,columnIndex] };
			}
			++columnIndex;
		}
		++rowIndex;
	}

	return std::nullopt;
}

void AdjacencyMatrix::reorganizeMatrixAfterVertexRemoval(std::size_t indexOfDeletedVertex,
		std::size_t numberOfActiveVertices)
{
	std::size_t newRow{ 0 };
	std::size_t newColumn{ 0 };
	for (std::size_t row{ 0 }; row < numberOfActiveVertices; ++row, ++newRow)
	{
		for (std::size_t column{ 0 }; column < numberOfActiveVertices; ++column, ++newColumn)
		{
			if (row == indexOfDeletedVertex)
				++row;

			if (column == indexOfDeletedVertex)
				++column;

			m_matrix[newRow,newColumn] = m_matrix[row,column];
		}

		newColumn = 0;
	}

	for (auto row : std::views::iota(0ull, numberOfActiveVertices))
	{
		m_matrix[row,numberOfActiveVertices - 1] = 0;
	}

	for (auto column : std::views::iota(0ull, numberOfActiveVertices))
	{
		m_matrix[numberOfActiveVertices - 1,column] = 0;
	}
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

void AdjacencyMatrix::setMainFontText(const sf::Font& font)
{
	m_mainFont = &font;
	initializeTopText();
}

void AdjacencyMatrix::setMonoFontText(const sf::Font& font)
{
	m_monoFont = &font;
	initializeMatrixText();
}

const Matrix& AdjacencyMatrix::getMatrix() const
{
	return m_matrix;
}

void AdjacencyMatrix::initializeTopText()
{
	m_topText.setFont(*m_mainFont);
	m_topText.setString("Adjacency matrix");
	m_topText.setPosition(90.0f, 0.0f);
	m_topText.setCharacterSize(25);
	m_topText.setFillColor(color::text);
}

void AdjacencyMatrix::initializeMatrixTextCoordinates()
{
	for (int rowIndex{ 1 }; auto& row : m_matrixTextCoordinates)
	{
		for (int columnIndex{ 1 }; auto& [x, y] : row)
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
		text.setFont(*m_monoFont);
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
	verticalLine.setFillColor(color::line);
	verticalLine.setPosition({ constants::adjacencyMatrixWidth, 0.0f });

	sf::RectangleShape horizontalLine{ { constants::adjacencyMatrixWidth, 2.0f } };
	horizontalLine.setFillColor(color::line);
	horizontalLine.setPosition({ 0.0f, constants::adjacencyMatrixHeight });

	m_borderLines[0] = verticalLine;
	m_borderLines[1] = horizontalLine;
}

std::string AdjacencyMatrix::getNumbersFromMatrix(std::size_t row)
{
	std::string matrixRowString{ "   " };
	for (std::size_t j{ 0 }; j < constants::maxNumberOfVertices; ++j)
		matrixRowString += std::to_string(m_matrix[row - 1,j]) + "  ";

	return matrixRowString;
}
