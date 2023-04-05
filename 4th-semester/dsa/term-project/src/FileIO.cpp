#include "FileIO.h"

#include <fstream>

void writeAirlinesToFile(const Airline& airline, const std::string& filename)
{
	std::ofstream outputFile{ filename };

	outputFile << "Airline: " << airline.getName() << "\n\n";
	Airport* current{ airline.getHead() };
	while (current != nullptr)
	{
		outputFile << "airport: " << current->getName() << '\n';
		current = current->getNext();
	}
}

void readAirlinesFromFile(const Airline& airline, const std::string& filename);
