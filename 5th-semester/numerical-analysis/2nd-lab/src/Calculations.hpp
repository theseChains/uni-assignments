#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

double getFunctionValue(double x);
double getFirstDerivative(double x);
double getSecondDerivative(double x);

double getNextXForIterativeMethod(double lastX);
double getNextXForNewtonsMethod(double lastX);
double getNextXForModifiedNewtonsMethod(double lastX, double firstX);

#endif
