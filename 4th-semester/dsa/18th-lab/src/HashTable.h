#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <array>
#include <optional>
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

struct Node
{
	Node* next{};
	std::string value{};
};

struct Element
{
	Node* head{};
	Node* tail{};
	std::string value{};
};

struct HashTable
{
	Element array[constants::maxTableSize]{};
	int size{ 0 };
};

std::optional<int> addToTable(HashTable& table, const std::string& newValue);
std::pair<bool, int> findInTable(const HashTable& table, const std::string& valueToFind);
void printTable(const HashTable& table);

void fillTable(HashTable& table);

#endif
