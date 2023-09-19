#ifndef ITERATIVE_METHOD_HPP
#define ITERATIVE_METHOD_HPP

#include <fstream>

void printIterativeMethodTableHeader(std::ofstream& outputFile);
void runIterativeMethodLoop(const double epsilon, std::ofstream& outputFile,
        double lastX, double lastY, double lastZ);
void runIterativeMethod(std::ofstream& outputFile, double lastX, double lastY,
        double lastZ);

#endif
