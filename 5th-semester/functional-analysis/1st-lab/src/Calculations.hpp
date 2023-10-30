#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

#include <cmath>

double getFunctionValue(double x);
double getLeftEndApproximationNu();
double getRightEndApproximationMu();
double getNextForIterativeMethod(double lastX);
double getContractionCoefficient();
int getAprioryEstimate(double firstX, double firstApproximation);
int getAposterioryEstimate(double firstX);

#endif
