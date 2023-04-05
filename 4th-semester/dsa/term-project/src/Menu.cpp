#include "Menu.h"

#include "Airline.h"
#include "FileIO.h"

#include <iostream>
#include <string>

void printMenu()
{
	std::cout << "\n1:  add new airport\n";
	std::cout << "2:  find airport\n";
	std::cout << "3:  print airports\n";
	std::cout << "4:  remove an airport\n";
	std::cout << "5:  write airlines to file\n";
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

void handleAirportAddition(Airline& airline)
{
	std::cout << "\nenter airport name: ";
	std::string name{ getString() };
	airline.addAirport(name);
}

void handleAirportSearch(const Airline& airline)
{
	if (airline.isAirportListEmpty())
	{
		std::cout << "\nthe airport list is empty\n";
		return;
	}

	std::cout << "\nenter airport name: ";
	std::string name{ getString() };
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

void handleAirportRemoval(Airline& airline)
{
	if (airline.isAirportListEmpty())
	{
		std::cout << "\nthe airport list is empty\n";
		return;
	}

	std::cout << "\nenter airport name to remove: ";
	std::string name{ getString() };
	airline.removeAirport(name);
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
		case 4:
			handleAirportRemoval(airline);
			break;
		case 5:
			writeAirlinesToFile(airline, "test.txt");
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
