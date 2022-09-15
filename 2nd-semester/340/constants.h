#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
	inline constexpr int surnameIndex{ 0 };
	inline constexpr int nameIndex{ 1 };
	inline constexpr int middleNameIndex{ 2 };
	inline constexpr int positionIndex{ 3 };
	inline constexpr int countryIndex{ 4 };
	inline constexpr int regionIndex{ 5 };
	inline constexpr int cityIndex{ 6 };
	inline constexpr int streetIndex{ 7 };
	inline constexpr int houseIndex{ 8 };
	inline constexpr int apartmentIndex{ 9 };
	inline constexpr int totalAttributes{ 10 };
}

enum class Choice
{
	sort,
	find
};

enum class Output
{
	console,
	file
};

#endif