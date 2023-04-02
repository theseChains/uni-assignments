#include "Airline.h"

#include <iostream>

Airline::Airline() : m_name{ "Airline" }, m_airportHead{ nullptr }
{
}

Airline::Airline(const std::string& name) : m_name{ name }, m_airportHead{ nullptr }
{
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
		newAirport->setPrev(nullptr);
		m_airportHead = newAirport;
	}
	// add at the beginning
	else if (m_airportHead->getName() >= airportName)
	{
		newAirport->setNext(m_airportHead);
		newAirport->setPrev(nullptr);
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
			newAirport->setPrev(previous);
			previous->setNext(newAirport);
		}
		// add before current
		else
		{
			newAirport->setNext(current);
			newAirport->setPrev(previous);
			previous->setNext(newAirport);
			current->setPrev(newAirport);
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
	while (current->getName() != airportName)
		current = current->getNext();

	if (current == m_airportHead)
		m_airportHead = current->getNext();

	if (current->getPrev() != nullptr)
		current->getPrev()->setNext(current->getNext());
	if (current->getNext() != nullptr)
		current->getNext()->setPrev(current->getPrev());

	delete current;
}

void Airline::printAirports() const
{
	if (isAirportListEmpty())
	{
		std::cout << "\nthe airport list is empty\n";
		return;
	}

	Airport* current{ m_airportHead };
	while (current != nullptr)
	{
		std::cout << "airport: " << current->getName() << '\n';
		current = current->getNext();
	}
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
