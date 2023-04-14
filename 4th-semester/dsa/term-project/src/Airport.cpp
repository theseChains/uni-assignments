#include "Airport.h"

#include <iostream>

Airport::Airport() : m_name { "Aiport" }, m_next{ nullptr }
{
}

Airport::Airport(const std::string& name) : m_name { name }, m_next{ nullptr }
{
}

Airport::~Airport()
{
	Airplane* current{ m_airplaneHead };
	Airplane* old{ current };
	while (current != nullptr)
	{
		current = current->getNext();
		delete old;
		old = current;
	}
}

bool Airport::isAirportEmpty() const
{
	return m_airplaneHead == nullptr;
}

void Airport::addAirplane(const std::string& airplaneModel, int yearOfManufacture)
{
	Airplane* newAirplane{ new Airplane{ airplaneModel, yearOfManufacture } };

	if (m_airplaneHead == nullptr)
	{
		newAirplane->setNext(nullptr);
		newAirplane->setPrev(nullptr);
		m_airplaneHead = newAirplane;
	}
	// add at the beginning
	else if (m_airplaneHead->getModel() >= airplaneModel)
	{
		newAirplane->setNext(m_airplaneHead);
		newAirplane->setPrev(nullptr);
		m_airplaneHead = newAirplane;
	}
	else
	{
		Airplane* current{ m_airplaneHead };
		Airplane* previous{ m_airplaneHead };
		while (current != nullptr && current->getModel() < airplaneModel)
		{
			if (current->getNext() != nullptr && current->getNext()->getModel() < airplaneModel)
				previous = previous->getNext();

			current = current->getNext();
		}

		// append
		if (current == nullptr)
		{
			newAirplane->setNext(nullptr);
			newAirplane->setPrev(previous);
			previous->setNext(newAirplane);
		}
		// add before current
		else
		{
			newAirplane->setNext(current);
			newAirplane->setPrev(previous);
			previous->setNext(newAirplane);
			current->setPrev(newAirplane);
		}
	}
}

bool Airport::findAirplane(const std::string& airplaneModel)
{
	Airplane* current{ m_airplaneHead };
	while (current != nullptr)
	{
		if (current->getModel() == airplaneModel)
			return true;

		current = current->getNext();
	}

	return false;
}

void Airport::removeAirplane(const std::string& airplaneModel)
{
	if (m_airplaneHead == nullptr)
	{
		std::cout << "\nthe airplane list is empty\n";
		return;
	}

	if (!findAirplane(airplaneModel))
	{
		std::cout << "\ncouldn't find the airplane \"" << airplaneModel << "\"\n";
		return;
	}

	Airplane* current{ m_airplaneHead };
	while (current->getModel() != airplaneModel)
		current = current->getNext();

	if (current == m_airplaneHead)
		m_airplaneHead = current->getNext();

	if (current->getPrev() != nullptr)
		current->getPrev()->setNext(current->getNext());
	if (current->getNext() != nullptr)
		current->getNext()->setPrev(current->getPrev());

	delete current;
}

void Airport::printAirplanes() const
{
	if (isAirportEmpty())
	{
		std::cout << "\nthe airport is empty\n";
		return;
	}

	Airplane* current{ m_airplaneHead };
	while (current != nullptr)
	{
		std::cout << "airplane: " << current->getModel() << '\n';
		current = current->getNext();
	}
}

void Airport::setName(const std::string& name)
{
	m_name = name;
}

void Airport::setNext(Airport* const next)
{
	m_next = next;
}

const std::string& Airport::getName() const
{
	return m_name;
}

std::string& Airport::getName()
{
	return m_name;
}

Airport* Airport::getNext() const
{
	return m_next;
}

Airplane* Airport::getHead() const
{
	return m_airplaneHead;
}
