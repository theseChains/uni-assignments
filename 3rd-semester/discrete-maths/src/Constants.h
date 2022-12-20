#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <random>

namespace rnd
{
	inline std::mt19937 mt{ std::random_device{}() };

	inline unsigned char getUchar(int min, int max)
	{
		std::uniform_int_distribution range{ min, max };
		return static_cast<unsigned char>(range(mt));
	}
}

namespace constants
{
	inline constexpr int windowWidth{ 1280 };
	inline constexpr int windowHeight{ 720 };

	inline constexpr int adjacencyMatrixWidth{ 390 };
	inline constexpr int adjacencyMatrixHeight{ 310 };

	inline constexpr float minimumDistanceBetweenVertices{ 35.0f };
	inline constexpr float vertexRadius{ 15.0f };
	inline constexpr int maxNumberOfVertices{ 10 };

	inline constexpr float labelOffset{ 25.0f };

	inline constexpr int chosenVertexPointCount{ 4 };
	inline constexpr int defaultVertexPointCount{ 30 };
}

namespace coords
{
	inline constexpr float columnOffsetBetweenValues{ 33.0f };
	inline constexpr float columnScreenOffset{ 19.0f };

	inline constexpr float rowOffsetBetweenValues{ 25.0f };
	inline constexpr float rowScreenOffset{ 29.0f };
}

#endif
