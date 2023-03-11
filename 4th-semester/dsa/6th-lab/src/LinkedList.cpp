#include "LinkedList.h"

#include <iostream>

bool isListEmpty(const Node* head)
{
	return (head->next == nullptr);
}

void addToList(Node* head, AddOption option)
{
	if (option == AddOption::afterElement && isListEmpty(head))
	{
		std::cout << "\nenter new value: ";
		int newValue{};
		std::cin >> newValue;

		Node* newNode{ new Node{} };
		newNode->next = nullptr;
		newNode->value = newValue;
		head->next = newNode;
	}
	else if (option == AddOption::afterElement && !isListEmpty(head))
	{
		std::cout << "\nenter value after which to insert the element: ";
		int value{};
		std::cin >> value;

		Node* current{ head->next };
		while (current != nullptr && current->value != value)
			current = current->next;

		if (current == nullptr)
		{
			std::cout << "\ncouldn't find an element with value " << value << " in the list\n";
			return;
		}

		std::cout << "\nenter new value: ";
		int newValue{};
		std::cin >> newValue;

		Node* newNode{ new Node{} };
		newNode->next = current->next;
		newNode->value = newValue;
		current->next = newNode;
	}
	else if (option == AddOption::beforeElement)
	{
		if (isListEmpty(head))
		{
			std::cout << "\ncannot add before element for an empty list\n";
			return;
		}

		std::cout << "\nenter value before which to insert the element: ";
		int value{};
		std::cin >> value;

		Node* previous{ head };
		Node* current{ head->next };

		while (current != nullptr && current->value != value)
		{
			current = current->next;
			previous = previous->next;
		}

		if (current == nullptr)
		{
			std::cout << "\ncouldn't find an element with value " << value << " in the list\n";
			return;
		}

		std::cout << "\nenter new value: ";
		int newValue{};
		std::cin >> newValue;

		Node* newNode{ new Node{} };
		newNode->next = current;
		newNode->value = newValue;
		previous->next = newNode;
	}
}

void removeFromList(Node* head, int itemToRemove)
{
	if (isListEmpty(head))
	{
		std::cout << "the list is empty, cannot remove\n";
		return;
	}

	Node* current{ head->next };
	Node* previous{ head };
	while (current != nullptr && current->value != itemToRemove)
	{
		current = current->next;
		previous = previous->next;
	}

	if (current == nullptr)
	{
		std::cout << "\ncouldn't find element with value " << itemToRemove << " in list\n";
		return;
	}

	previous->next = current->next;
	delete current;
}

void findInList(const Node* head, int itemToFind)
{
	Node* current{ head->next };
	int index{ 0 };
	while (current != nullptr && current->value != itemToFind)
	{
		current = current->next;
		++index;
	}

	if (current == nullptr)
	{
		std::cout << "\ncouldn't find an element with value " << itemToFind << " in the list\n";
		return;
	}

	std::cout << "\nvalue " << itemToFind << " was found at index " << index << '\n';
}

void printList(Node* head)
{
	if (isListEmpty(head))
	{
		std::cout << "the list is empty";
		return;
	}

	Node* current{ head->next };
	while (current != nullptr)
	{
		std::cout << current->value << ' ';
		current = current->next;
	}
}
