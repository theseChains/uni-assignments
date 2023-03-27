#include "HashTable.h"

#include <iostream>
#include <ranges>

int hashFunction(const std::string& value)
{
	int index{};
	for (const auto& character : value)
		index += static_cast<int>(character);

	return (index % 10);
}

void addToTable(HashTable& table, const std::string& newValue)
{
	if (std::ranges::find(table.array, newValue) == std::end(table.array))
	{
		std::cout << "\ncouldn't find key " << newValue << " in the list of keys\n";
		return;
	}

	int keyIndex{ hashFunction(newValue) };
	table.array[keyIndex] = newValue;
}

void printTable(const HashTable& table)
{
	for (const auto& element : table.array)
		std::cout << element << ' ';
	std::cout << '\n';
}
