#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants
{
	inline const std::string defaultInputFile{ "in.txt" };
	inline const std::string defaultOutputFile{ "out.txt" };
	inline constexpr int substringLength{ 3 };
	inline constexpr int startIndex{ 2 };
	inline constexpr int aASCII{ 97 };
	inline constexpr int cASCII{ 99 };
}

enum class StreamType
{
	input,
	output
};

#endif