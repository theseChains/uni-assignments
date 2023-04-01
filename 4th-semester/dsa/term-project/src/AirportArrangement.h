#ifndef AIRPORT_ARRANGEMENT_H
#define AIRPORT_ARRANGEMENT_H

#include "Airport.h"

class AirportArrangement
{
private:
	Airport* m_head{};

public:
	AirportArrangement();

	Airport* getHead() const;
};

#endif
