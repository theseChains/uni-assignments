#ifndef RELAXATION_METHOD_HPP
#define RELAXATION_METHOD_HPP

#include <fstream>

void printModifiedNewtonsMethodTableHeader(std::ofstream& outputFile,
                                           const double epsilon);
void runModifiedNewtonsMethodLoop(const double epsilon, const double delta,
                                  std::ofstream& outputFile, double lastX,
                                  double lastY);
void runModifiedNewtonsMethod(std::ofstream& outputFile, double lastX,
                              double lastY);

#endif
