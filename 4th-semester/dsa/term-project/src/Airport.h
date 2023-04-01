#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

class Airport
{
private:
	std::string m_name{};

	Airport* m_next{};
	Airport* m_prev{};

public:
	Airport();
	Airport(const std::string& name);

	void setName(const std::string& name);
	void setNext(Airport* const next);
	void setPrev(Airport* const prev);

	const std::string& getName() const;
	std::string& getName();
	Airport* getNext() const;
	Airport* getPrev() const;
};

#endif
