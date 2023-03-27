#include "Menu.h"
#include "HashTable.h"

#include <iostream>
#include <random>

void printMenu()
{
	std::cout << "\n1:  add key to table\n";
	std::cout << "3:  print table\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

std::string getString()
{
	std::string string{};
	std::cin >> string;
	return string;
}

void hanldeTableAddition(HashTable& table)
{
	std::cout << "\nenter key value to add: ";
	std::string value{ getString() };
	addToTable(table, value);
}

void handleTablePrinting(const HashTable& table)
{
	std::cout << '\n';
	printTable(table);
}

void handleCommand(HashTable& table, int command)
{
	switch (command)
	{
		case 1:
			hanldeTableAddition(table);
			break;
		case 2:
			break;
		case 3:
			handleTablePrinting(table);
			break;
		case 4:
			break;
		case 5:
			break;
	}
}

void runMenuLoop()
{
	HashTable table{};
	for (int i{ 0 }; i < constants::maxSize; ++i)
		table.array[i] = "EMPTY";

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(table, command);
	}
}
