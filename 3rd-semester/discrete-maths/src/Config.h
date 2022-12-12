#ifndef CONFIG_H
#define CONFIG_H

#include <array>

namespace constants
{
	inline constexpr int windowWidth{ 1280 };
	inline constexpr int windowHeight{ 720 };
}

namespace background
{
	inline constexpr int red{ 20 };
	inline constexpr int green{ 20 };
	inline constexpr int blue{ 36 };
}

namespace vertex
{
	inline constexpr int red{ 200 };
	inline constexpr int green{ 200 };
	inline constexpr int blue{ 255 };
}

namespace text
{
	inline constexpr int red{ 190 };
	inline constexpr int green{ 190 };
	inline constexpr int blue{ 255 };
}

namespace coords
{
	inline constexpr float columnOffsetBetweenValues{ 33.0f };
	inline constexpr float columnScreenOffset{ 19.0f };

	inline constexpr float rowOffsetBetweenValues{ 25.0f };
	inline constexpr float rowScreenOffset{ 29.0f };
}

#endif
