#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

double getFunctionValue(double x);

double getQ(double x);
double calculateFirstNewtonsInterpolationFormula(double x);

double getT(double x);
double calculateSecondNewtonsInterpolationFormula(double x);

double calculateLagrangeInterpolationFormula(double x);

double getDerivativeValue(double x);
double getClosestX0(double x);
double getClosestXn(double x);

double calculateDerivativeFirstNewtonsInterpolation(double x);
double calculateDerivativeSecondNewtonsInterpolation(double x);

#endif
