#ifndef AIRLINE_H
#define AIRLINE_H

#include "AirportArrangement.h"

#include <string>

class Airline
{
private:
	std::string m_name{};
	AirportArrangement m_airports{};

public:
	Airline();
	Airline(const std::string& name);

	void setName(const std::string& name);

	const std::string& getName() const;
	std::string& getName();
};

#endif
