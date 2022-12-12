#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

#include <array>

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();

	void handleEvent(const sf::Event& event, sf::RenderWindow& window);
	void update();
	void draw(sf::RenderWindow& window) const;

private:
	void initializeTopText();
	void initializeMatrixTextCoordinates();
	void initializeMatrixText();
	void initializeMatrixNumberBounds();
	void initializeBorderLines();

	std::string getNumbersFromMatrix(std::size_t row);

private:
	using TextCoordinates = std::array<std::array<std::pair<float, float>, 10>, 10>;
	std::array<std::array<bool, 10>, 10> m_matrix{};

	sf::Font m_font{};
	sf::Text m_topText{};
	std::array<sf::Text, 11> m_matrixText{};

	// king krule - borderline
	std::array<sf::RectangleShape, 2> m_borderLines;

	TextCoordinates m_matrixTextCoordinates{};
	std::array<std::array<sf::FloatRect, 10>, 10> m_matrixNumberBounds{};
};

#endif
