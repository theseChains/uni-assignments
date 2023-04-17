#ifndef FILE_IO_H
#define FILE_IO_H

#include "Airline.h"

void writeAirlinesToFile(const Airline& airline, const std::string& filename);
void readAirlinesFromFile(Airline& airline, const std::string& filename);

#endif
