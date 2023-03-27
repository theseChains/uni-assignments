#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <array>
#include <string>
#include <tuple>

namespace constants
{
	inline constexpr int maxSize{ 10 };
}

namespace config
{
	inline std::array<std::string, constants::maxSize> keys{
		"auto",
		"union",
		"constexpr",
		"volatile",
		"explicit",
		"friend",
		"inline",
		"virtual",
		"for",
		"template"
	};
}

struct HashTable
{
	std::string array[constants::maxSize]{};
};

void addToTable(HashTable& table, const std::string& newValue);
std::pair<bool, int> findInTable(const HashTable& table, const std::string& valueToFind);
void printTable(const HashTable& table);

#endif
