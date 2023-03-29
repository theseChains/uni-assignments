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

void addToAuxiliaryList(Node*& head, const std::string& newValue, int& numberOfComaprisons)
{
	if (head == nullptr)
	{
		head = new Node{};
		head->value = newValue;
		head->next = nullptr;

		return;
	}

	Node* current{ head };
	while (current->next != nullptr)
	{
		++numberOfComaprisons;
		current = current->next;
	}

	Node* newElement{ new Node{} };
	newElement->value = newValue;
	newElement->next = nullptr;
	current->next = newElement;
}

std::optional<int> addToTable(HashTable& table, const std::string& newValue)
{
	if (!isKeyValid(newValue))
	{
		std::cout << "\ncouldn't find key " << newValue << " in the list of keys\n";
		return std::nullopt;
	}

	int numberOfComaprisons{ 0 };

	int index{ getValueIndex(newValue) };
	int currentIndex{ index };
	++numberOfComaprisons;
	if (table.array[currentIndex].value != "EMPTY")
		addToAuxiliaryList(table.array[currentIndex].head, newValue, numberOfComaprisons);
	else
		table.array[currentIndex].value = newValue;

	return numberOfComaprisons;
}

std::pair<bool, int> findInTable(const HashTable& table, const std::string& valueToFind)
{
	int numberOfComaprisons{ 0 };
	int valueIndex{ getValueIndex(valueToFind) };
	Element tableElement{ table.array[valueIndex] };

	++numberOfComaprisons;
	if (tableElement.value == valueToFind)
		return { true, valueIndex };

	Node* current{ tableElement.head };
	while (current != nullptr && current->value != valueToFind)
		current = current->next;

	if (current == nullptr)
		return { false, valueIndex };

	return { true, valueIndex };
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
