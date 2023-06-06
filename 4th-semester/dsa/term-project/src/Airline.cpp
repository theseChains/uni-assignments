#include "Airline.h"

#include <iostream>
#include <iomanip>

Airline::Airline() : m_name{ "Airline" }, m_airportHead{ nullptr }
{
}

Airline::Airline(const std::string& name) : m_name{ name }, m_airportHead{ nullptr }
{
}

Airline::~Airline()
{
	Airport* current{ m_airportHead };
	Airport* old{ current };
	while (current != nullptr)
	{
		current = current->getNext();
		delete old;
		old = current;
	}
}

bool Airline::isAirportListEmpty() const
{
	return m_airportHead == nullptr;
}

void Airline::addAirport(const std::string& airportName)
{
	Airport* newAirport{ new Airport{ airportName } };

	if (m_airportHead == nullptr)
	{
		newAirport->setNext(nullptr);
		m_airportHead = newAirport;
	}
	// add at the beginning
	else if (m_airportHead->getName() >= airportName)
	{
		newAirport->setNext(m_airportHead);
		m_airportHead = newAirport;
	}
	else
	{
		Airport* current{ m_airportHead };
		Airport* previous{ m_airportHead };
		while (current != nullptr && current->getName() < airportName)
		{
			if (current->getNext() != nullptr && current->getNext()->getName() < airportName)
				previous = previous->getNext();

			current = current->getNext();
		}

		// append
		if (current == nullptr)
		{
			newAirport->setNext(nullptr);
			previous->setNext(newAirport);
		}
		// add before current
		else
		{
			newAirport->setNext(current);
			previous->setNext(newAirport);
		}
	}
}

bool Airline::findAirport(const std::string& airportName) const
{
	Airport* current{ m_airportHead };
	while (current != nullptr)
	{
		if (current->getName() == airportName)
			return true;

		current = current->getNext();
	}

	return false;
}

void Airline::removeAirport(const std::string& airportName)
{
	if (m_airportHead == nullptr)
	{
		std::cout << "\nthe airport list is empty\n";
		return;
	}

	if (!findAirport(airportName))
	{
		std::cout << "\ncouldn't find the airport \"" << airportName << "\"\n";
		return;
	}

	Airport* current{ m_airportHead };
	Airport* previous{ nullptr };

	if (current != nullptr && current->getName() == airportName)
	{
		m_airportHead = current->getNext();
		delete current;
		return;
	}

	while (current->getName() != airportName)
	{
		previous = current;
		current = current->getNext();
	}

	previous->setNext(current->getNext());

	delete current;
}

void Airline::printAirports() const
{
	std::cout << "airline: " << m_name << '\n';
	if (isAirportListEmpty())
	{
		std::cout << "\nthe airport list is empty\n";
		return;
	}

	std::cout << std::string(50, '-') << '\n';
	Airport* current{ m_airportHead };
	while (current != nullptr)
	{
		std::cout << "airport: " << current->getName() << '\n';
		current->printAirplanes();
		current = current->getNext();
		std::cout << std::string(50, '-') << '\n';
	}
}

void Airline::addAirplane(const std::string& airportName, const std::string& airplaneModel,
	int yearOfManufacture)
{
	Airport* current{ m_airportHead };
	while (current != nullptr && current->getName() != airportName)
		current = current->getNext();

	if (current == nullptr)
	{
		std::cout << "couldn't find airport with the name " << airportName << '\n';
		return;
	}

	current->addAirplane(airplaneModel, yearOfManufacture);
}

void Airline::findAirplane(const std::string& airplaneModel) const
{
	Airport* current{ m_airportHead };
	int numberOfFoundAirplanes{ 0 };
	while (current != nullptr)
	{
		if (current->findAirplane(airplaneModel))
		{
			std::cout << "airplane " << airplaneModel << " found in airport " << current->getName()
				<< '\n';
			++numberOfFoundAirplanes;
		}

		current = current->getNext();
	}

	if (numberOfFoundAirplanes == 0)
		std::cout << "airplane " << airplaneModel << " was not found\n";
}

void Airline::deleteAirplane(const std::string& airplaneModel)
{
	Airport* current{ m_airportHead };
	bool removed{ false };
	while (current != nullptr)
	{
		if (current->removeAirplane(airplaneModel))
		{
			std::cout << "removed airplane " << airplaneModel << " from airport "
				<< current->getName() << '\n';
			removed = true;
		}
		current = current->getNext();
	}

	if (!removed)
		std::cout << "\ncouldn't find airplane " << airplaneModel << " in the airport list\n";
}

void Airline::setName(const std::string& name)
{
	m_name = name;
}

const std::string& Airline::getName() const
{
	return m_name;
}

std::string& Airline::getName()
{
	return m_name;
}

Airport* Airline::getHead() const
{
	return m_airportHead;
}
