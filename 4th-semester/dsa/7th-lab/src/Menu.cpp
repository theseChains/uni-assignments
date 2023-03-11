#include "Menu.h"
#include "LinkedList.h"

#include <iostream>
#include <optional>

void printMenu()
{
	std::cout << "\n1:  add element to list\n";
	std::cout << "2:  remove element from list\n";
	std::cout << "3:  print main list\n";
	std::cout << "4:  search for value in list\n";
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

void handleListRemoval(Node* head)
{
	if (isListEmpty(head))
	{
		std::cout << "\nthe list is empty, cannot remove\n";
		return;
	}

	std::cout << "\nenter value to remove: ";
	int valueToRemove{};
	std::cin >> valueToRemove;
	removeFromList(head, valueToRemove);
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

void handleCommand(Node* head, int command)
{
	switch (command)
	{
		case 1:
			handleListAddition(head);
			break;
		case 2:
			handleListRemoval(head);
			break;
		case 3:
			handleListPrinting(head);
			break;
		case 4:
			handleListSearch(head);
			break;
	}
}

void runMenuLoop()
{
	Node* head{ new Node{} };
	head->next = head;
	head->prev = head;

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(head, command);
	}
}
