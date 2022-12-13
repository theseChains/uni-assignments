#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
	inline constexpr int windowWidth{ 1280 };
	inline constexpr int windowHeight{ 720 };

	inline constexpr int adjacencyMatrixWidth{ 390 };
	inline constexpr int adjacencyMatrixHeight{ 310 };

	inline constexpr float minimumDistanceBetweenVertices{ 50.0f };
	inline constexpr float vertexRadius{ 15.0f };
	inline constexpr int maxNumberOfVertices{ 10 };

	inline constexpr float labelOffset{ 25.0f };
}

namespace coords
{
	inline constexpr float columnOffsetBetweenValues{ 33.0f };
	inline constexpr float columnScreenOffset{ 19.0f };

	inline constexpr float rowOffsetBetweenValues{ 25.0f };
	inline constexpr float rowScreenOffset{ 29.0f };
}

#endif
