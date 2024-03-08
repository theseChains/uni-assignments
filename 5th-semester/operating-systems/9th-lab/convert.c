#include <stdio.h>
/* Print a list of convertions from gallons to liters */
int main()
{
    int low,high,incr;
    float gals,ltrs;
    low = 1;
    high = 20;
    incr = 1;
    gals = (float)(low);
    while (gals <= (float)(high))
    {
        ltrs = (gals * 3.785f);
        printf("%4.0f %6.2f\n", gals, ltrs);
        gals = gals + 1;
    }
}
