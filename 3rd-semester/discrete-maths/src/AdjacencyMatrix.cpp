#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix() : m_matrix{}
{
	m_font.loadFromFile("../res/sansation.ttf");

	m_topText.setFont(m_font);
	m_topText.setString("Adjacency matrix");
	m_topText.setCharacterSize(25);
	m_topText.setFillColor(sf::Color{ 200, 200, 255 });
}

void AdjacencyMatrix::handleEvent()
{

}

void AdjacencyMatrix::draw(sf::RenderWindow& window)
{
	window.draw(m_topText);
}
