#ifndef RELAXATION_METHOD_HPP
#define RELAXATION_METHOD_HPP

#include <fstream>

void printRelaxationMethodTableHeader(std::ofstream& outputFile,
                                      const double epsilon);
void runRelaxationMethodLoop(const double epsilon, std::ofstream& outputFile,
                             double lastX, double lastY, double lastZ);
void runRelaxationMethod(std::ofstream& outputFile, double lastX, double lastY,
                         double lastZ);

#endif
