#include "HashTable.h"

#include <iostream>
#include <ranges>

int hashFunction(const std::string& value)
{
	int index{};
	for (const auto& character : value)
		index += static_cast<int>(character);

	index %= constants::maxSize;

	return index;
}

bool isKeyValid(const std::string& value)
{
	for (const auto& key : config::keys)
		if (key == value)
			return true;

	return false;
}

void addToTable(HashTable& table, const std::string& newValue)
{
	if (!isKeyValid(newValue))
	{
		std::cout << "\ncouldn't find key " << newValue << " in the list of keys\n";
		return;
	}

	auto [found, foundIndex]{ findInTable(table, newValue) };
	if (found)
	{
		std::cout << "\nelement with value " << newValue << " is already in the table\n";
		return;
	}

	int index{ hashFunction(newValue) };
	table.array[index] = newValue;
}

std::pair<bool, int> findInTable(const HashTable& table, const std::string& valueToFind)
{
	int valueIndex{ hashFunction(valueToFind) };
	if (table.array[valueIndex] == valueToFind)
		return { true, valueIndex };
	else
		return { false, valueIndex };
}

void removeFromTable(HashTable& table, const std::string& valueToRemove)
{
	if (!isKeyValid(valueToRemove))
	{
		std::cout << "\nvalue " << valueToRemove << " is not in the list of keys\n";
		return;
	}

	auto [found, foundIndex]{ findInTable(table, valueToRemove) };
	if (!found)
	{
		std::cout << "\ncouldn't find element with value " << valueToRemove << " in the table\n";
		return;
	}

	int valueIndex{ hashFunction(valueToRemove) };
	table.array[valueIndex].clear();
}

void printTable(const HashTable& table)
{
	for (int i{ 0 }; i < constants::maxSize; ++i)
	{
		std::cout << i << ": " << table.array[i] << '\n';
	}
}

void fillTable(HashTable& table)
{
	for (const auto& key : config::keys)
		addToTable(table, key);
}
