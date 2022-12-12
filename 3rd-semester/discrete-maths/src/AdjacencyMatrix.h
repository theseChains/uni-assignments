#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

// the adjacency matrix should have a fixed size... otherwise it will just be a disaster...
// i'm thinking of restricting the max amount of vertices to 10, should be a good size i think
// so the number of rows and columns is 10

// so what is an adjacency matrix exactly...
// the adjacency matrix consists of a text on the top, which is 16 characters long
// then there is the vertices row, the matrix itself is 10x10, each nubmer (0 or 1) being 15x15 px

// hmm.. i think we could make it a little bigger..

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();

	void handleEvent();
	void draw(sf::RenderWindow& window);

private:
	std::array<std::array<bool, 10>, 10> m_matrix{};

	sf::Text m_topText{};
	sf::Font m_font{};
};

#endif
