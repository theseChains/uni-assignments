#include "Airline.h"

Airline::Airline() : m_name{ "Airline" }, m_airports{}
{
}

Airline::Airline(const std::string& name) : m_name{ name }, m_airports{}
{
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
