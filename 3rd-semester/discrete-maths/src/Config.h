#ifndef CONFIG_H
#define CONFIG_H

#include <array>

#include <SFML/Graphics/Color.hpp>

namespace constants
{
	inline constexpr int windowWidth{ 1280 };
	inline constexpr int windowHeight{ 720 };

	inline constexpr int adjacencyMatrixWidth{ 390 };
	inline constexpr int adjacencyMatrixHeight{ 310 };
}

namespace background
{
	inline const sf::Color color{ 20, 20, 36 };
}

namespace vertex
{
	inline const sf::Color color{ 200, 200, 255 };
}

namespace text
{
	inline const sf::Color color{ 190, 190, 255 };
}

namespace line
{
	inline const sf::Color color{ 65, 158, 230 };
}

namespace chosen
{
	inline const sf::Color color{ 0, 47, 108 };
}

namespace coords
{
	inline constexpr float columnOffsetBetweenValues{ 33.0f };
	inline constexpr float columnScreenOffset{ 19.0f };

	inline constexpr float rowOffsetBetweenValues{ 25.0f };
	inline constexpr float rowScreenOffset{ 29.0f };
}

#endif
