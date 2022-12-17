#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

#include <array>
#include <optional>
#include <tuple>

#include "FontHolder.h"

class AdjacencyMatrix
{
public:
	struct IndicesAndValue
	{
		std::size_t rowIndex{};
		std::size_t columnIndex{};
		bool matrixValue{};
	};

	AdjacencyMatrix();

	std::optional<IndicesAndValue> handleLeftMouseClick(sf::RenderWindow& window,
			std::size_t numberOfActiveVertices);
	void reorganizeMatrixAfterVertexRemoval(std::size_t indexOfDeletedVertex,
			std::size_t numberOfActiveVertices);
	void update();
	void draw(sf::RenderWindow& window) const;

	void setMainFontText(const sf::Font& font);
	void setMonoFontText(const sf::Font& font);

	std::array<std::array<bool, 10>, 10> getMatrix() const;

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

	const sf::Font* m_mainFont{};
	const sf::Font* m_monoFont{};
	sf::Text m_topText{};
	std::array<sf::Text, 11> m_matrixText{};

	// king krule - borderline
	std::array<sf::RectangleShape, 2> m_borderLines;

	TextCoordinates m_matrixTextCoordinates{};
	std::array<std::array<sf::FloatRect, 10>, 10> m_matrixNumberBounds{};
};

#endif
