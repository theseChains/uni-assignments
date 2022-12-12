#include "AdjacencyMatrix.h"

#include <iostream>
#include <string>

AdjacencyMatrix::AdjacencyMatrix() : m_matrix{}
{
	m_font.loadFromFile("../res/FiraMono-Medium.otf");

	initializeTopText();
	initializeMatrixText();
}

void AdjacencyMatrix::handleEvent()
{

}

void AdjacencyMatrix::draw(sf::RenderWindow& window) const
{
	window.draw(m_topText);

	for (const auto& text : m_matrixText)
		window.draw(text);
}

void AdjacencyMatrix::initializeTopText()
{
	m_topText.setFont(m_font);
	m_topText.setString("   Adjacency matrix");
	m_topText.setCharacterSize(25);
	m_topText.setFillColor(sf::Color{ 200, 200, 255 });
}

void AdjacencyMatrix::initializeMatrixText()
{
	for (auto& text : m_matrixText)
	{
		text.setFont(m_font);
		text.setCharacterSize(15);
	}

	// there has to be an easier way...
	m_matrixText[0].setString("    v0 v1 v2 v3 v4 v5 v6 v7 v8 v9");
	m_matrixText[0].setPosition(0.0f, 30.0f);

	for (int i{ 1 }; i < m_matrixText.size(); ++i)
	{
		std::string matrixRowString{ "   " };
		for (int j{ 0 }; j < 10; ++j)
		{
			matrixRowString += std::to_string(m_matrix[i - 1][j]) + "  ";
		}
		m_matrixText[i].setString("v" + std::to_string(i - 1) + matrixRowString);
		m_matrixText[i].setPosition(0.0f, 25.0f * (i + 1));
	}
}
