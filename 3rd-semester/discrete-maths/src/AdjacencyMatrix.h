#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();

	void handleEvent();
	void draw(sf::RenderWindow& window) const;

private:
	void initializeTopText();
	void initializeMatrixText();

private:
	std::array<std::array<bool, 10>, 10> m_matrix{};

	sf::Font m_font{};
	sf::Text m_topText{};
	std::array<sf::Text, 11> m_matrixText{};
};

#endif
