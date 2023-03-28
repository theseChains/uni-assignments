#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <array>
#include <string>
#include <tuple>

namespace constants
{
	inline constexpr int maxTableSize{ 13 };
	inline constexpr int maxKeysSize{ 10 };
}

namespace config
{
	inline std::array<std::string, constants::maxKeysSize> keys{
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
	std::string array[constants::maxTableSize]{};
};

void addToTable(HashTable& table, const std::string& newValue);
std::pair<bool, int> findInTable(const HashTable& table, const std::string& valueToFind);
void removeFromTable(HashTable& table, const std::string& valueToRemove);
void printTable(const HashTable& table);

#endif
