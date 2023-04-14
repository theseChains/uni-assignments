#ifndef AIRPORT_H
#define AIRPORT_H

#include "Airplane.h"

#include <string>

class Airport
{
private:
	std::string m_name{};

	Airport* m_next{};
	Airport* m_prev{};

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
	void setPrev(Airport* const prev);

	const std::string& getName() const;
	std::string& getName();
	Airport* getNext() const;
	Airport* getPrev() const;
};

#endif
