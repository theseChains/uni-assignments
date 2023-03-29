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

void addToAuxiliaryList(Node*& head, const std::string& newValue)
{
	Node* newElement{ new Node{} };
	newElement->value = newValue;
	newElement->next = nullptr;
	if (head == nullptr)
		head = newElement;
	else
		head->next = newElement;
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
	int currentIndex{ index };
	++numberOfComaprisons;

	if (table.array[currentIndex].value != "EMPTY")
	{
		addToAuxiliaryList(table.array[currentIndex].head, newValue);
	}
	else
	{
		table.array[currentIndex].value = newValue;
		++table.size;
	}

	return numberOfComaprisons;
}

void printAuxiliaryList(Node* head)
{
	Node* current{ head };
	while (current != nullptr)
	{
		std::cout << current->value << ' ';
		current = current->next;
	}
	std::cout << '\n';
}

void printTable(const HashTable& table)
{
	for (const auto& element : table.array)
	{
		std::cout << element.value << ' ';
		printAuxiliaryList(element.head);
	}
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
