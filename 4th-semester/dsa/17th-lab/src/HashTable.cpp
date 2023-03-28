#include "HashTable.h"

#include <iostream>
#include <ranges>

void hashFunction(int& index)
{
	index %= constants::maxTableSize;
}

int getValueIndex(const std::string& value)
{
	int index{};
	for (const auto& character : value)
		index += static_cast<int>(character);
	hashFunction(index);

	return index;
}

bool isKeyValid(const std::string& value)
{
	for (const auto& key : config::keys)
		if (key == value)
			return true;

	return false;
}

std::optional<int> addToTable(HashTable& table, const std::string& newValue)
{
	if (!isKeyValid(newValue))
	{
		std::cout << "\ncouldn't find key " << newValue << " in the list of keys\n";
		return std::nullopt;
	}

	if (table.size == constants::maxTableSize)
	{
		std::cout << "\nthe table is full\n";
		return std::nullopt;
	}

	int numberOfComaprisons{ 0 };

	int index{ getValueIndex(newValue) };
	int iteration{ 1 };
	int currentIndex{ index };
	++numberOfComaprisons;
	while (table.array[currentIndex] != "EMPTY" && iteration <= constants::maxTableSize - 2)
	{
		++numberOfComaprisons;
		currentIndex = (index + iteration) % constants::maxTableSize;
		++iteration;
	}

	table.array[currentIndex] = newValue;
	++table.size;

	return numberOfComaprisons;
}

std::pair<bool, int> findInTable(const HashTable& table, const std::string& valueToFind)
{
	int valueIndex{ getValueIndex(valueToFind) };
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

	int valueIndex{ getValueIndex(valueToRemove) };
	table.array[valueIndex] = "EMPTY";
	--table.size;
}

void printTable(const HashTable& table)
{
	for (const auto& element : table.array)
		std::cout << element << ' ';
	std::cout << '\n';
}

void fillTable(HashTable& table)
{
	int numberOfComaprisons{ 0 };
	for (const auto& key : config::keys)
	{
		auto added{ addToTable(table, key) };
		if (added)
			numberOfComaprisons += added.value();
	}

	std::cout << "\ntotal number of comparisons after filling the table: "
		<< numberOfComaprisons << '\n';
}
