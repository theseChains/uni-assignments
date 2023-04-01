#ifndef AIRLINE_H
#define AIRLINE_H

#include "Airport.h"

#include <string>

class Airline
{
private:
	std::string m_name{};

	Airport* m_airportHead{};

public:
	Airline();
	Airline(const std::string& name);

	void addAirport(const std::string& airportName);
	void findAirport(const std::string& airportName);
	void removeAirport(const std::string& airportName);
	void showAirports() const;

	void setName(const std::string& name);

	const std::string& getName() const;
	std::string& getName();
};

#endif
