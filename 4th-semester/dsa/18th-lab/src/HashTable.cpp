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

void addToAuxiliaryList(Node*& head, const std::string& newValue, int& numberOfComaprisons)
{
	++numberOfComaprisons;
	if (head == nullptr)
	{
		head = new Node{};
		head->value = newValue;
		head->next = nullptr;

		return;
	}

	Node* current{ head };
	++numberOfComaprisons;
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
	int numberOfComaprisons{ 0 };

	auto [found, valueIndex, number]{ findInTable(table, newValue) };
	if (found)
	{
		std::cout << "the value " << newValue << " was found in the table\n";
		return std::nullopt;
	}

	int index{ hashFunction(newValue) };
	int currentIndex{ index };
	++numberOfComaprisons;
	if (!table.array[currentIndex].value.empty())
		addToAuxiliaryList(table.array[currentIndex].head, newValue, numberOfComaprisons);
	else
		table.array[currentIndex].value = newValue;

	return numberOfComaprisons;
}

std::tuple<bool, int, int> findInTable(const HashTable& table, const std::string& valueToFind)
{
	int numberOfComparisons{ 0 };
	int valueIndex{ hashFunction(valueToFind) };
	Element tableElement{ table.array[valueIndex] };

	++numberOfComparisons;
	if (tableElement.value.empty())
		return { false, valueIndex, numberOfComparisons };

	++numberOfComparisons;
	if (tableElement.value == valueToFind)
		return { true, valueIndex, numberOfComparisons };

	Node* current{ tableElement.head };
	++numberOfComparisons;
	while (current != nullptr && current->value != valueToFind)
	{
		current = current->next;
		++numberOfComparisons;
	}

	++numberOfComparisons;
	if (current == nullptr)
		return { false, valueIndex, numberOfComparisons };

	return { true, valueIndex, numberOfComparisons };
}

bool findInAuxiliaryList(Node* head, const std::string& valueToFind)
{
	Node* current{ head };
	while (current != nullptr)
	{
		if (current->value == valueToFind)
			return true;
		current = current->next;
	}

	return false;
}

void removeFromAuxiliaryList(Node*& head, const std::string& valueToRemove)
{
	Node* current{ head };
	Node* previous{};

	if (current != nullptr && current->value == valueToRemove)
	{
		head = head->next;
		delete current;
		return;
	}

	while (current != nullptr && current->value != valueToRemove)
	{
		previous = current;
		current = current->next;
	}

	if (current == nullptr)
		return;

	previous->next = current->next;
	delete current;
}

void removeFromTable(HashTable& table, const std::string& valueToRemove)
{
	int valueIndex{ hashFunction(valueToRemove) };
	std::string& tableValue{ table.array[valueIndex].value };
	if (tableValue == valueToRemove)
	{
		if (table.array[valueIndex].head == nullptr)
			tableValue.clear();
		else
		{
			Node*& tableElementHead{ table.array[valueIndex].head };
			Node* temporary{ tableElementHead };
			tableValue = tableElementHead->value;
			tableElementHead = tableElementHead->next;
			delete temporary;
		}
	}
	else if (findInAuxiliaryList(table.array[valueIndex].head, valueToRemove))
		removeFromAuxiliaryList(table.array[valueIndex].head, valueToRemove);
	else
		std::cout << "\ncouldn't find element " << valueToRemove << " in the table\n";
}

void printAuxiliaryList(Node* head)
{
	Node* current{ head };
	while (current != nullptr)
	{
		std::cout << current->value;
		if (current->next != nullptr)
			std::cout << ", ";
		current = current->next;
	}
	std::cout << '\n';
}

void printTable(const HashTable& table)
{
	for (int i{ 0 }; i < constants::maxTableSize; ++i)
	{
		std::cout << i << ": " << table.array[i].value << " - ";
		printAuxiliaryList(table.array[i].head);
	}
	std::cout << '\n';
}

void fillTable(HashTable& table)
{
	int numberOfComaprisons{ 0 };
	for (const auto& key : config::names)
	{
		auto added{ addToTable(table, key) };
		if (added)
			numberOfComaprisons += added.value();
	}

	std::cout << "\ntotal number of comparisons after filling the table: "
		<< numberOfComaprisons << '\n';
}
