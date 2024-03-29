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
        lines = true;
    }
    else
    {
        lines = false;
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
    else
    {
        return "working with lines";
    }
}
