#include "Menu.h"
#include "Airline.h"

#include <iostream>
#include <string>

void printMenu()
{
	std::cout << "\n1:  add new airport\n";
	std::cout << "2:  find airport\n";
	std::cout << "3:  print airports\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

void handleAirportAddition(Airline& airline)
{
	std::cout << "\nenter airport name: ";
	std::string name{};
	std::cin >> name;
	airline.addAirport(name);
}

void handleAirportSearch(const Airline& airline)
{
	std::cout << "\nenter airport name: ";
	std::string name{};
	std::cin >> name;
	bool found{ airline.findAirport(name) };
	if (found)
		std::cout << "\nairport " << name << " was found\n";
	else
		std::cout << "\nairport " << name << " was not found\n";
}

void handleAirlinePrinting(const Airline& airline)
{
	std::cout << '\n';
	airline.printAirports();
}

void handleCommand(Airline& airline, int command)
{
	switch (command)
	{
		case 1:
			handleAirportAddition(airline);
			break;
		case 2:
			handleAirportSearch(airline);
			break;
		case 3:
			handleAirlinePrinting(airline);
			break;
	}
}

void runMenuLoop()
{
	Airline airline{};

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(airline, command);
	}
}
