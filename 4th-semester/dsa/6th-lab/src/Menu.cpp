#include "Menu.h"
#include "LinkedList.h"

#include <iostream>
#include <optional>

void printMenu()
{
	std::cout << "\n1:  add element to list\n";
	std::cout << "2:  remove element from list\n";
	std::cout << "3:  print main list\n";
	std::cout << "4:  print auxiliary list\n";
	std::cout << "5:  search for value in list\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

std::optional<AddOption> getOption()
{
	int number{ getNumber() };
	switch (number)
	{
		case 0:
			return AddOption::beforeElement;
		case 1:
			return AddOption::afterElement;
		default:
			std::cout << "\nincorrect addition option, try again\n";
			return std::nullopt;
	}
}

void handleListAddition(Node* head)
{
	std::cout << "\n0 - add before specified element\n1 - add after specified element\n";
	auto option{ getOption() };
	while (!option)
		option = getOption();

	addToList(head, option.value());
}

void handleListRemoval(Node* head, Node* auxiliary)
{
	if (isListEmpty(head))
	{
		std::cout << "\nthe list is empty, cannot remove\n";
		return;
	}

	std::cout << "\n0 - delete the element from list\n1 - move element to auxiliary list\n";
	int option{};
	std::cin >> option;

	std::cout << "\nenter value to remove: ";
	int valueToRemove{};
	std::cin >> valueToRemove;

	if (option == 0)
		removeFromList(head, valueToRemove);
	else if (option == 1)
	{
		// code duplication, i don't care
		Node* current{ head->next };
		Node* previous{ head };
		while (current != nullptr && current->value != valueToRemove)
		{
			current = current->next;
			previous = previous->next;
		}

		if (current == nullptr)
		{
			std::cout << "\ncouldn't find element with value " << valueToRemove << " in list\n";
			return;
		}

		Node* temporary{ current };
		previous->next = current->next;
		temporary->next = auxiliary->next;
		auxiliary->next = temporary;
	}
	else
	{
		std::cout << "\nincorrect option\n";
	}
}

void handleListSearch(const Node* head)
{
	if (isListEmpty(head))
	{
		std::cout << "\nthe list is empty, cannot search for elements\n";
		return;
	}

	std::cout << "enter item to find: ";
	int itemToFind{ getNumber() };
	findInList(head, itemToFind);
}

void handleListPrinting(Node* head)
{
	std::cout << '\n';
	printList(head);
	std::cout << '\n';
}

void handleCommand(Node* head, Node* auxiliary, int command)
{
	switch (command)
	{
		case 1:
			handleListAddition(head);
			break;
		case 2:
			handleListRemoval(head, auxiliary);
			break;
		case 3:
			handleListPrinting(head);
			break;
		case 4:
			handleListPrinting(auxiliary);
			break;
		case 5:
			handleListSearch(head);
			break;
	}
}

void runMenuLoop()
{
	Node* head{ new Node{} };
	Node* auxiliary{ new Node{} };

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(head, auxiliary, command);
	}

	destroyList(head);
	destroyList(auxiliary);
}
