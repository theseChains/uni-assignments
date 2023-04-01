#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>

class Airplane
{
private:
	std::string m_model{};
	int m_yearOfManufacture{};

	Airplane* m_next{};
	Airplane* m_prev{};
};

#endif
