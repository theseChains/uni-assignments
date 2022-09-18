#include "util.h"

int rnd::getNumber(int min, int max)
{
    std::uniform_int_distribution range(min, max);
    return range(mt);
}
