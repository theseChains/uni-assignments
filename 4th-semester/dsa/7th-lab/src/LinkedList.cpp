#include "LinkedList.h"

#include <iostream>

bool isListEmpty(const Node* head)
{
	return (head->next == head);
}

void addToList(Node* head, AddOption option)
{
	if (option == AddOption::afterElement && isListEmpty(head))
	{
		std::cout << "\nenter new value: ";
		int newValue{};
		std::cin >> newValue;

		Node* newNode{ new Node{} };
		newNode->next = head;
		newNode->prev = head;
		head->next = newNode;
		head->prev = newNode;
		newNode->value = newValue;
	}
	else if (option == AddOption::afterElement && !isListEmpty(head))
	{
		std::cout << "\nenter value after which to insert the element: ";
		int value{};
		std::cin >> value;

		Node* current{ head->next };
		while (current != head && current->value != value)
			current = current->next;

		if (current == head)
		{
			std::cout << "\ncouldn't find an element with value " << value << " in the list\n";
			return;
		}

		std::cout << "\nenter new value: ";
		int newValue{};
		std::cin >> newValue;

		Node* newNode{ new Node{} };
		newNode->next = current->next;
		newNode->prev = current;
		current->next->prev = newNode;
		current->next = newNode;
		newNode->value = newValue;
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

		Node* current{ head->next };
		while (current != head && current->value != value)
			current = current->next;

		if (current == head)
		{
			std::cout << "\ncouldn't find an element with value " << value << " in the list\n";
			return;
		}

		std::cout << "\nenter new value: ";
		int newValue{};
		std::cin >> newValue;

		Node* newNode{ new Node{} };
		newNode->next = current;
		newNode->prev = current->prev;
		current->prev->next = newNode;
		current->prev = newNode;
		newNode->value = newValue;
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
	while (current != head && current->value != itemToRemove)
		current = current->next;

	if (current == head)
	{
		std::cout << "\ncouldn't find element with value " << itemToRemove << " in list\n";
		return;
	}

	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
}

void findInList(const Node* head, int itemToFind)
{
	Node* current{ head->next };
	int index{ 0 };
	while (current != head && current->value != itemToFind)
	{
		current = current->next;
		++index;
	}

	if (current == head)
	{
		std::cout << "\ncouldn't find an element with value " << itemToFind << " in the list\n";
		return;
	}

	std::cout << "\nvalue " << itemToFind << " was found at index " << index << '\n';
}

void printList(Node* head, int mode)
{
	if (isListEmpty(head))
	{
		std::cout << "the list is empty";
		return;
	}

	if (mode == 0)
	{
		Node* current{ head->next };
		while (current != head)
		{
			std::cout << current->value << ' ';
			current = current->next;
		}
	}
	else if (mode == 1)
	{
		Node* current{ head->prev };
		while (current != head)
		{
			std::cout << current->value << ' ';
			current = current->prev;
		}
	}
	else
	{
		std::cout << "\nincorrect print mode\n";
	}
}
