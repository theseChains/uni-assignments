#include "LinkedList.h"

#include <iostream>

bool isListEmpty(const Node* head)
{
	return (head->next == head);
}

bool isNodeListEmpty(const NodeList* listHead)
{
	return (listHead->next == nullptr);
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

void addToNodeList(NodeList* head, AddOption option)
{
	if (option == AddOption::afterElement && isNodeListEmpty(head))
	{
		std::cout << "\nenter new list id: ";
		int newValue{};
		std::cin >> newValue;

		NodeList* newList{ new NodeList{} };
		newList->head = new Node{};
		newList->next = nullptr;
		newList->head->next = newList->head;
		newList->head->value = newValue;
		head->next = newList;
	}
	else if (option == AddOption::afterElement && !isNodeListEmpty(head))
	{
		std::cout << "\nenter value after which to insert the element: ";
		int value{};
		std::cin >> value;

		NodeList* current{ head->next };
		while (current != nullptr && current->head->value != value)
			current = current->next;

		if (current == nullptr)
		{
			std::cout << "\ncouldn't find an element with value " << value << " in the list\n";
			return;
		}

		std::cout << "\nenter new list id: ";
		int newValue{};
		std::cin >> newValue;

		NodeList* newList{ new NodeList{} };
		newList->head = new Node{};
		newList->next = current->next;
		newList->head->value = newValue;
		newList->head->next = newList->head;
		current->next = newList;
	}
	else if (option == AddOption::beforeElement)
	{
		if (isNodeListEmpty(head))
		{
			std::cout << "\ncannot add before element for an empty list\n";
			return;
		}

		std::cout << "\nenter value before which to insert the element: ";
		int value{};
		std::cin >> value;

		NodeList* previous{ head };
		NodeList* current{ head->next };

		while (current != nullptr && current->head->value != value)
		{
			current = current->next;
			previous = previous->next;
		}

		if (current == nullptr)
		{
			std::cout << "\ncouldn't find an element with value " << value << " in the list\n";
			return;
		}

		std::cout << "\nenter new list id: ";
		int newValue{};
		std::cin >> newValue;

		NodeList* newList{ new NodeList{} };
		newList->head = new Node{};
		newList->next = current;
		newList->head->value = newValue;
		newList->head->next = newList->head;
		previous->next = newList;
	}
}

void removeFromNodeList(NodeList* head, int listIdToRemove)
{
	if (isNodeListEmpty(head))
	{
		std::cout << "the list of lists is empty, cannot remove\n";
		return;
	}

	NodeList* current{ head->next };
	NodeList* previous{ head };
	while (current != nullptr && current->head->value != listIdToRemove)
	{
		current = current->next;
		previous = previous->next;
	}

	if (current == nullptr)
	{
		std::cout << "\ncouldn't find list with id " << listIdToRemove << " in list of lists\n";
		return;
	}

	previous->next = current->next;
	if (!isListEmpty(current->head))
		destroyList(current->head);
	delete current;
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

int getNumberOfElementsInList(const Node* head)
{
	Node* current{ head->next };
	int numberOfElements{ 0 };
	while (current != head)
	{
		current = current->next;
		++numberOfElements;
	}

	return numberOfElements;
}

void findInList(const Node* head, int itemToFind, int mode)
{
	Node* current{ nullptr };
	int index{};
	if (mode == 0)
	{
		current = head->next;
		index = 0;
		while (current != head && current->value != itemToFind)
		{
			current = current->next;
			++index;
		}
	}
	else if (mode == 1)
	{
		current = head->prev;
		index = getNumberOfElementsInList(head) - 1;
		while (current != head && current->value != itemToFind)
		{
			current = current->prev;
			--index;
		}
	}
	else
	{
		std::cout << "\nincorrect search option\n";
		return;
	}

	if (current == head)
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
	while (current != head)
	{
		std::cout << current->value << ' ';
		current = current->next;
	}
}

void printNodeList(NodeList* head)
{
	if (isNodeListEmpty(head))
	{
		std::cout << "the list is empty";
		return;
	}

	NodeList* current{ head->next };
	while (current != nullptr)
	{
		std::cout << current->head->value << ": ";
		printList(current->head);
		current = current->next;
		std::cout << '\n';
	}
}

void destroyList(Node* head)
{
	Node* current{};
	head->prev->next = nullptr;
	while (head != nullptr)
	{
		current = head;
		head = head->next;
		delete current;
	}
}
