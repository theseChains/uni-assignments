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

	~Airline();

	bool isAirportListEmpty() const;
	void addAirport(const std::string& airportName);
	bool findAirport(const std::string& airportName) const;
	void removeAirport(const std::string& airportName);
	void printAirports() const;

	void addAirplane(const std::string& airportName, const std::string& airplaneModel,
		int yearOfManufacture);
	void findAirplane(const std::string& airplaneModel) const;
	void deleteAirplane(const std::string& airplaneModel);

	void setName(const std::string& name);

	const std::string& getName() const;
	std::string& getName();

	Airport* getHead() const;
};

#endif
