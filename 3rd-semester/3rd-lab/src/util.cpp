#include "util.h"

int rnd::getNumber(int min, int max)
{
    std::uniform_int_distribution range(min, max);
    return range(mt);
}

float rnd::getFloat(int min, int max)
{
    std::uniform_int_distribution range(min, max);
    return static_cast<float>(range(mt));
}

float rnd::getRealNumber(float min, float max)
{
    std::uniform_real_distribution<float> range(min, max);
    return range(mt);
}

void mode::shift()
{
    if (circles)
    {
        circles = false;
        rectangles = true;
    }
    else if (rectangles)
    {
        rectangles = false;
        ellipses = true;
    }
    else if (ellipses)
    {
        ellipses = false;
        quadrangles = true;
    }
    else
    {
        quadrangles = false;
        circles = true;
    }
}

std::string mode::get()
{
    if (circles)
    {
        return "working with circles";
    }
    else if (rectangles)
    {
        return "working with rectangles";
    }
    else if (ellipses)
    {
        return "working with ellipses";
    }
    else
    {
        return "working with quadrangles";
    }
}
