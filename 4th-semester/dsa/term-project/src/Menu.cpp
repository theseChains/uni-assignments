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
	std::cout << "5:  add new airplane to airport\n";
	std::cout << "6:  find an airplane in an airport\n";
	std::cout << "7:  remove an airplane from an airport\n";
	std::cout << "8:  set a new name for the airline\n";
	std::cout << "-1: exit\n";
}

int Menu::getNumber()
{
	while (true)
	{
		int number{};
		std::cin >> number;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\ninvalid input, try again: ";
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return number;
		}
	}
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
	airline.findAirplane(model);
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
	airline.deleteAirplane(model);
}

void Menu::handleAirlineNameChange(Airline& airline)
{
	std::cout << "\nenter the name for the new airline: ";
	std::string airlineName{ getString() };
	airline.setName(airlineName);
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
			handleAirplaneAddition(airline);
			break;
		case 6:
			handleAirplaneSearch(airline);
			break;
		case 7:
			handleAirplaneRemoval(airline);
			break;
		case 8:
			handleAirlineNameChange(airline);
			break;
	}
}

void Menu::runMenuLoop()
{
	Airline airline{};
	FileIO fileIO{};
	if (!fileIO.readAirlinesFromFile(airline, "airline.txt"))
	{
		std::cout << "enter the name of the airline: ";
		std::string airlineName{ getString() };
		airline.setName(airlineName);
	}

	airline.printAirports();
	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(airline, command);
	}

	std::cout << "save the structure to airline.txt? might overwrite the previous structure\n";
	std::cout << "0 - don't save\n1 - save\n";
	int choice{ getNumber() };
	if (choice)
		fileIO.writeAirlinesToFile(airline, "airline.txt");
}
