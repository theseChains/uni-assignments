#ifndef SEIDEL_METHOD_HPP
#define SEIDEL_METHOD_HPP

#include <fstream>

void printSeidelMethodTableHeader(std::ofstream& outputFile);
void runSeidelMethodLoop(const double epsilon, std::ofstream& outputFile,
        double lastX, double lastY, double lastZ);
void runSeidelMethod(std::ofstream& outputFile, double lastX, double lastY,
        double lastZ);

#endif
