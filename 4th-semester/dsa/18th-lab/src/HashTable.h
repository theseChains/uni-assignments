#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <array>
#include <optional>
#include <string>
#include <tuple>

namespace constants
{
	inline constexpr int maxTableSize{ 6 };
	inline constexpr int maxKeysSize{ 13 };
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
		"concept",
		"template",
		"mutable",
		"noexcept",
		"nullptr"
	};
}

struct Node
{
	Node* next{ nullptr };
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
};

std::optional<int> addToTable(HashTable& table, const std::string& newValue);
std::pair<bool, int> findInTable(const HashTable& table, const std::string& valueToFind);
void removeFromTable(HashTable& table, const std::string& valueToRemove);
void printTable(const HashTable& table);

void fillTable(HashTable& table);

#endif