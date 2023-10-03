#ifndef ITERATIVE_METHOD_HPP
#define ITERATIVE_METHOD_HPP

#include <fstream>

void printIterativeMethodTableHeader(std::ofstream& outputFile,
                                     const double epsilon);

void runIterativeMethodLoop(const double epsilon, const double delta,
                            std::ofstream& outputFile, double lastX);
void runIterativeMethod(std::ofstream& outputFile, double lastX);

#endif
