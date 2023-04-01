#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

class Airport
{
private:
	std::string m_name{};

	Airport* m_next{};
	Airport* m_prev{};
};

#endif
