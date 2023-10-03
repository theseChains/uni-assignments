#ifndef NEWTONS_METHOD_HPP
#define NEWTONS_METHOD_HPP

#include <fstream>

void printNewtonsMethodTableHeader(std::ofstream& outputFile,
                                   const double epsilon, const double delta);
void runNewtonsMethodLoop(const double epsilon, const double delta,
                          std::ofstream& outputFile, double lastX);
void runNewtonsMethod(std::ofstream& outputFile, double lastX);

#endif
