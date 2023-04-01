#include "AirportArrangement.h"

AirportArrangement::AirportArrangement()
{
	m_head = new Airport{};
}

Airport* AirportArrangement::getHead() const
{
	return m_head;
}
