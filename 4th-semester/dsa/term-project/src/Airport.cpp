#include "Airport.h"

Airport::Airport() : m_name { "Aiport" }, m_next{ nullptr }, m_prev{ nullptr }
{
}

Airport::Airport(const std::string& name)
	: m_name { name }, m_next{ nullptr }, m_prev{ nullptr }
{
}

void Airport::setName(const std::string& name)
{
	m_name = name;
}

void Airport::setNext(Airport* const next)
{
	m_next = next;
}

void Airport::setPrev(Airport* const prev)
{
	m_prev = prev;
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

Airport* Airport::getPrev() const
{
	return m_prev;
}
