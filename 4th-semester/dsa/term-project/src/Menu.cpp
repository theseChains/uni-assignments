#include "Menu.h"

#include "FileIO.h"

#include <iostream>
#include <limits>

void Menu::printMenu()
{
	std::cout << "\n1:  add new airport\n";
	std::cout << "2:  find airport\n";
	std::cout << "3:  print airline\n";
	std::cout << "4:  remove an airport\n";
	std::cout << "5:  write airlines to file\n";
	std::cout << "6:  add new airplane to airport\n";
	std::cout << "7:  find an airplane in an airport\n";
	std::cout << "8:  remove an airplane from an airport\n";
	std::cout << "-1: exit\n";
}

int Menu::getNumber()
{
	int number{};
	std::cin >> number;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return number;
}

std::string Menu::getString()
{
	std::string string{};
	std::getline(std::cin, string);
	return string;
}

void Menu::handleAirportAddition(Airline& airline)
{
	std::cout << "\nenter airport name: ";
	std::string name{ getString() };
	airline.addAirport(name);
}

void Menu::handleAirportSearch(const Airline& airline)
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

void Menu::handleAirlinePrinting(const Airline& airline)
{
	std::cout << '\n';
	airline.printAirports();
}

void Menu::handleAirportRemoval(Airline& airline)
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

void Menu::handleAirplaneAddition(Airline& airline)
{
	if (airline.isAirportListEmpty())
	{
		std::cout << "\nthe airport list is empty\n";
		return;
	}

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

void Menu::handleAirplaneSearch(const Airline& airline)
{
	if (airline.isAirportListEmpty())
	{
		std::cout << "\nthe airport list is empty\n";
		return;
	}

	std::cout << "enter the model of the airplane: ";
	std::string model{ getString() };
	Airport* current{ airline.getHead() };
	int numberOfFoundAirplanes{ 0 };
	while (current != nullptr)
	{
		if (current->findAirplane(model))
		{
			std::cout << "airplane " << model << " found in airport" << current->getName() << '\n';
			++numberOfFoundAirplanes;
		}

		current = current->getNext();
	}

	if (numberOfFoundAirplanes == 0)
		std::cout << "airplane " << model << " was not found\n";
}

void Menu::handleAirplaneRemoval(Airline& airline)
{
	if (airline.isAirportListEmpty())
	{
		std::cout << "\nthe airport list is empty\n";
		return;
	}

	std::cout << "\nenter airplane name to remove: ";
	std::string model{ getString() };
	Airport* current{ airline.getHead() };
	while (current != nullptr)
	{
		if (current->removeAirplane(model))
			std::cout << "removed airplane " << model << " from airport "
				<< current->getName() << '\n';
		current = current->getNext();
	}
}

void Menu::handleCommand(Airline& airline, int command)
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
			handleAirplaneSearch(airline);
			break;
		case 8:
			handleAirplaneRemoval(airline);
			break;
	}
}

void Menu::runMenuLoop()
{
	Airline airline{};
	if (!readAirlinesFromFile(airline, "input.txt"))
	{
		std::cerr << "invalid input\n";
		return;
	}

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(airline, command);
	}
}
