#include <stdio.h>
#include <math.h>

int factorial(int number)
{
    if (number == 0 || number == 1)
        return 1;

    return (number * factorial(number - 1));
}

int main()
{
    printf("Enter n: ");
    int n = 0;
    scanf("%d", &n);

    double denominator = 1.0;
    for (int i = 2; i <= 2 * n; i += 2)
    {
        denominator *= factorial(i);
    }

    double numerator = pow(factorial(n + 1), n);
    double result = numerator / denominator;

    printf("result: %lf\n", result);

    return 0;
}
