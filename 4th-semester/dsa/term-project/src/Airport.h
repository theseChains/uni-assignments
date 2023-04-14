#ifndef AIRPORT_H
#define AIRPORT_H

#include "Airplane.h"

#include <string>

class Airport
{
private:
	std::string m_name{};

	Airport* m_next{};

	Airplane* m_airplaneHead{};

public:
	Airport();
	Airport(const std::string& name);

	~Airport();

	bool isAirportEmpty() const;
	void addAirplane(const std::string& airplaneModel, int yearOfManufacture);
	bool findAirplane(const std::string& airplaneModel);
	void removeAirplane(const std::string& airplaneModel);
	void printAirplanes() const;

	void setName(const std::string& name);
	void setNext(Airport* const next);

	const std::string& getName() const;
	std::string& getName();
	Airport* getNext() const;

	Airplane* getHead() const;
};

#endif
