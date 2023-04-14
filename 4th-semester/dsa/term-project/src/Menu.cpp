#include "Menu.h"

#include "Airline.h"
#include "FileIO.h"

#include <iostream>
#include <string>

void printMenu()
{
	std::cout << "\n1:  add new airport\n";
	std::cout << "2:  find airport\n";
	std::cout << "3:  print airline\n";
	std::cout << "4:  remove an airport\n";
	std::cout << "5:  write airlines to file\n";
	std::cout << "6:  add new airplane to airport\n";
	std::cout << "7:  find an airplane in an airport\n";
	std::cout << "8:  remove and airplane from an airport\n";
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
	// doesn't work
	// std::getline(std::cin, string);
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

void handleAirplaneAddition(Airline& airline)
{
	std::cout << "\nenter the name of the airport to which you want to add an airplane: ";
	std::string airportName{ getString() };

	Airport* currentAirport{ airline.getHead() };
	while (currentAirport != nullptr && currentAirport->getName() != airportName)
		currentAirport = currentAirport->getNext();

	if (currentAirport == nullptr)
	{
		std::cout << "\ncoudln't find an airport with the name " << airportName << '\n';
		return;
	}

	std::cout << "enter the model of the airplane: ";
	std::string airplaneModel{ getString() };
	std::cout << "enter the year of manufacture of the airplane: ";
	int yearOfManufacture{ getNumber() };

	currentAirport->addAirplane(airplaneModel, yearOfManufacture);
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
		case 6:
			handleAirplaneAddition(airline);
			break;
		case 7:
			break;
		case 8:
			break;
	}
}

void runMenuLoop()
{
	Airline airline{ "S7 airlines" };

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(airline, command);
	}
}
