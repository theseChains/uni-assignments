#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

double getNextX(double lastY, double lastZ);
double getNextY(double lastX, double lastZ);
double getNextZ(double lastX, double lastY);

double getResidualX(double x, double y, double z);
double getResidualY(double x, double y, double z);
double getResidualZ(double x, double y, double z);

#endif
