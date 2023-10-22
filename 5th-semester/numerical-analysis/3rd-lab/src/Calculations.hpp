#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

double getFirstFunctionValue(double x, double y);
double getSecondFunctionValue(double x, double y);

double getAlpha(double x);
double getBeta(double x);
double getGamma(double x);
double getDelta(double x);

double getNextXForIterativeMethod(double lastX, double lastY);
double getNextYForIterativeMethod(double lastX, double lastY);
double getNextXForNewtonsMethod(double lastX, double lastY);
double getNextYForNewtonsMethod(double lastX, double lastY);
double getNextXForModifiedNewtonsMethod(double lastX, double lastY,
                                        double firstX);
double getNextYForModifiedNewtonsMethod(double lastX, double lastY,
                                        double firstX);

#endif
