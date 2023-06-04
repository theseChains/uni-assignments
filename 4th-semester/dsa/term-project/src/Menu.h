#ifndef MENU_H
#define MENU_H

#include "Airline.h"

#include <string>

class Menu
{
public:
	void runMenuLoop();

	void printMenu();
	int getNumber();
	std::string getString();
	void handleAirportAddition(Airline& airline);
	void handleAirportSearch(const Airline& airline);
	void handleAirlinePrinting(const Airline& airline);
	void handleAirportRemoval(Airline& airline);
	void handleAirplaneAddition(Airline& airline);
	void handleAirplaneSearch(const Airline& airline);
	void handleAirplaneRemoval(Airline& airline);
	void handleAirlineClearing(Airline& airline);
	void handleAirlineNameChange(Airline& airline);
	void handleCommand(Airline& airline, int command);
};

#endif
