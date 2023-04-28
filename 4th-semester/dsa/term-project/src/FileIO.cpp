#include "FileIO.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>

void writeAirlinesToFile(const Airline& airline, const std::string& filename)
{
	std::ofstream outputFile{ filename };

	outputFile << "Airline: " << airline.getName() << "\n\n";
	Airport* currentAirport{ airline.getHead() };
	while (currentAirport != nullptr)
	{
		outputFile << "airport: " << currentAirport->getName() << '\n';

		Airplane* currentAirplane{ currentAirport->getHead() };
		while (currentAirplane != nullptr)
		{
			outputFile << "airplane: " << currentAirplane->getModel() << ' ' <<
				currentAirplane->getYearOfManufacture() << '\n';
			currentAirplane = currentAirplane->getNext();
		}

		currentAirport = currentAirport->getNext();
	}
}

bool readAirlinesFromFile(Airline& airline, const std::string& filename)
{
	if (!std::filesystem::exists(filename))
	{
		std::cerr << "\ncoudln't open file " << filename << '\n';
		return false;
	}

	if (std::filesystem::file_size(filename) == 0)
	{
		std::cerr << "\nfile " << filename << " is empty\n";
		return false;
	}

	std::ifstream inputFile{ filename };
	std::string line{};

	std::getline(inputFile, line);
	auto pos{ line.find(':') };
	if (pos != std::string::npos)
		airline.setName(line.substr(pos + 1));
	else
	{
		std::cout << "invalid input.txt: no airline name\n";
		return false;
	}

	while (std::getline(inputFile, line))
	{
		pos = line.find(':');
		if (pos == std::string::npos)
		{
			std::cout << "invalid input.txt: airport info\n";
			return false;
		}

		std::string currentAirportName{ line.substr(pos + 1) };
		airline.addAirport(currentAirportName);

		std::getline(inputFile, line);
		pos = line.find(':');
		if (pos == std::string::npos)
		{
			std::cout << "invalid input.txt: airplane info\n";
			return false;
		}

		std::string airplanesLine{ line.substr(pos + 1) };
		std::size_t startOfInfo{ 0 };
		std::size_t endOfInfo{ airplanesLine.find(',') };
		while (true)
		{
			std::string airplaneInfo{ airplanesLine.substr(startOfInfo, endOfInfo) };
			std::size_t endOfAirplaneModelInfo{ airplaneInfo.find(';') };
			std::string airplaneModel{ airplaneInfo.substr(startOfInfo, endOfAirplaneModelInfo) };
			int airplaneYearOfManufacture{
				std::stoi(airplaneInfo.substr(endOfAirplaneModelInfo + 1, endOfInfo)) };
			airline.addAirplane(currentAirportName, airplaneModel, airplaneYearOfManufacture);

			if (airplanesLine.find(',') == std::string::npos)
				break;
			airplanesLine = airplanesLine.substr(airplanesLine.find(',') + 1);
			endOfInfo = airplanesLine.find(',');
		}
	}

	return true;
}