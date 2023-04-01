#ifndef AIRLINE_H
#define AIRLINE_H

#include "AirportArrangement.h"

#include <string>

class Airline
{
private:
	std::string m_name{};
	AirportArrangement m_airports{};
};

#endif
