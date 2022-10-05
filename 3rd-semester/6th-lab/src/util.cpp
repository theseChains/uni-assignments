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
    if (all)
    {
        circular = true;
        all = false;
    }
    else if (circular)
    {
        quadrangular = true;
        circular = false;
    }
    else
    {
        all = true;
        quadrangular = false;
    }
}

std::string mode::get()
{
    if (all)
    {
        return "working with all shapes";
    }
    else if (circular)
    {
        return "working with circular";
    }
    else
    {
        return "working with quadrangular";
    }
}
