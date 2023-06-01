#ifndef FILE_IO_H
#define FILE_IO_H

#include "Airline.h"

#include <string>

class FileIO
{
public:
	void writeAirlinesToFile(const Airline& airline, const std::string& filename);
	bool readAirlinesFromFile(Airline& airline, const std::string& filename);

};

#endif
