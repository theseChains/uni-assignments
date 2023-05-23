#include "HashTable.h"

#include <iostream>
#include <ranges>

int hashFunction(const std::string& value)
{
	int index{};
	for (const auto& character : value)
		index += static_cast<int>(character);
	index %= constants::maxTableSize;

	return index;
}

std::optional<int> addToTable(HashTable& table, const std::string& newValue)
{
	if (table.size == constants::maxTableSize)
	{
		std::cout << "\nthe table is full\n";
		return std::nullopt;
	}

	int numberOfComaprisons{ 0 };
	auto [found, valueIndex, number]{ findInTable(table, newValue) };
	if (found)
	{
		std::cout << "the value " << newValue << " was found in the table\n";
		return std::nullopt;
	}

	int index{ hashFunction(newValue) };
	int iteration{ 1 };
	int currentIndex{ index };
	++numberOfComaprisons;
	while (!table.array[currentIndex].empty())
	{
		++numberOfComaprisons;
		currentIndex = (index + iteration) % constants::maxTableSize;
		++iteration;
	}

	table.array[currentIndex] = newValue;
	++table.size;

	return numberOfComaprisons;
}

std::tuple<bool, int, int> findInTable(const HashTable& table, const std::string& valueToFind)
{
	int valueIndex{ hashFunction(valueToFind) };
	int iteration{ 1 };
	int numberOfComparisons{ 0 };
	if (table.array[valueIndex].empty())
		return { false, valueIndex, numberOfComparisons };
	while (iteration <= constants::maxTableSize - 1)
	{
		++numberOfComparisons;
		if (table.array[valueIndex] == valueToFind)
			return { true, valueIndex, numberOfComparisons };

		++valueIndex;
		valueIndex %= constants::maxTableSize;

		++iteration;
	}

	return { false, valueIndex, numberOfComparisons };
}

void printTable(const HashTable& table)
{
	for (int i{ 0 }; i < constants::maxTableSize; ++i)
		std::cout << i << ": " << table.array[i] << '\n';
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
