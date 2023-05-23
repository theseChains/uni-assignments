#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <array>
#include <optional>
#include <string>
#include <tuple>

namespace constants
{
	inline constexpr int maxTableSize{ 10 };
	inline constexpr int maxKeysSize{ 10 };
}

namespace config
{
	inline constexpr std::array<std::string, constants::maxTableSize> keys{
		"Christian",
		"Stina",
		"Daniel",
		"Bertha",
		"Augustus",
		"Cosmo",
		"Edwarda",
		"Roberta",
		"Thyra",
		"Benita"
	};
}

struct HashTable
{
	std::string array[constants::maxTableSize]{};
	int size{ 0 };
};

std::optional<int> addToTable(HashTable& table, const std::string& newValue);
std::tuple<bool, int, int> findInTable(const HashTable& table, const std::string& valueToFind);
void printTable(const HashTable& table);

void fillTable(HashTable& table);

#endif
