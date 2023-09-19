#include "Calculations.hpp"

double getNextX(double lastY, double lastZ)
{
    return 5.0 / 4.0 + lastY / 4.0 + lastZ / 4.0;
}

double getNextY(double lastX, double lastZ)
{
    return -25.0 / 31.0 + lastX * 4.0 / 31.0 - lastZ * 21.0 / 31.0;
}

double getNextZ(double lastX, double lastY)
{
    return -5.0 / 3.0 + lastX * 2.0 / 3.0 - lastY / 6.0;
}

double getResidualX(double x, double y, double z)
{
    return 5.0 / 4.0 - x + y / 4.0 + z / 4.0;
}

double getResidualY(double x, double y, double z)
{
    return -25.0 / 31.0 - y + x * 4.0 / 31.0 - z * 21.0 / 31.0;
}

double getResidualZ(double x, double y, double z)
{
    return -5.0 / 3.0 - z + x * 2.0 / 3.0 - y / 6.0;
}
