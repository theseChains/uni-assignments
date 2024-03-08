#include "constants.hpp"

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

double getPx(double x)
{
    return (1.0 / std::sqrt(x * x + 1));
}

double getQx()
{
    return 1;
}

double getFx(double x)
{
    return x;
}

double getMi(double step, double x)
{
    return ((2 * step * step * getQx() - 4) / (2 + step * getPx(x)));
}

double getRi(double step, double x)
{
    return ((2 - step * getPx(x)) / (2 + step * getPx(x)));
}

double getPhi_i(double step, double x)
{
    return ((2 * step * step * getFx(x)) / (2 + step * getPx(x)));
}

double getCi(double mi, double ri, double previousCi)
{
    return (1 / (mi - ri * previousCi));
}

double getDi(double phi_i, double ri, double previousCi, double previousDi)
{
    return (phi_i - ri * previousCi * previousDi);
}

struct ForwardRunResult
{
    std::vector<double> xValues{};
    std::vector<double> miValues{};
    std::vector<double> riValues{};
    std::vector<double> phiValues{};
    std::vector<double> ciValues{};
    std::vector<double> diValues{};
};

ForwardRunResult forwardRun(int n)
{
    ForwardRunResult result{};
    double step{ (constants::b - constants::a) / n };

    double currentX{ constants::a };
    result.xValues.push_back(currentX);
    currentX += step;

    result.miValues.reserve(n + 1);
    result.riValues.reserve(n + 1);
    result.phiValues.reserve(n + 1);
    result.ciValues.reserve(n + 1);
    result.diValues.reserve(n + 1);

    for (int i{ 1 }; i < n; ++i)
    {
        result.xValues.push_back(currentX);
        result.miValues[i] = getMi(step, currentX);
        result.riValues[i] = getRi(step, currentX);
        result.phiValues[i] = getPhi_i(step, currentX);

        currentX += step;
    }
    result.xValues.push_back(currentX);

    result.ciValues.push_back(constants::alpha0 / (step * constants::alhpa1 - constants::alpha0));

    std::vector<double> diValues(n);
    result.diValues.push_back(constants::bigA * step / constants::alpha0);

    for (int i{ 1 }; i < n; ++i)
    {
        result.ciValues.push_back(getCi(result.miValues[i], result.riValues[i], result.ciValues[i - 1]));
        result.diValues.push_back(getDi(result.phiValues[i], result.riValues[i], result.ciValues[i - 1], result.diValues[i - 1]));
    }

    return result;
}

std::vector<double> backwardRun(const ForwardRunResult& result, int n)
{
    double step{ (constants::b - constants::a) / n };

    std::vector<double> yValues(n + 1);
    yValues[n] =
        (constants::bigB * step + constants::beta0 * result.ciValues[n - 1] * result.diValues[n - 1]) /
        (constants::beta0 * (1 + result.ciValues[n - 1]) + step * constants::beta1);

    for (int i{ n - 1 }; i >= 0; --i)
    {
        yValues[i] = result.ciValues[i] * (result.diValues[i] - yValues[i + 1]);
    }

    return yValues;
}

void printResults(const ForwardRunResult& forwardRunResult,
            const std::vector<double>& yValues, int n, std::ofstream& output)
{
    double step{ (constants::b - constants::a) / n };

    output << ",x,yi,mi,ri,phi_i,ci,di\n";
    for (int i{ 0 }; i <= n; ++i)
    {
        output << ',' << forwardRunResult.xValues[i] << ',';
        output << yValues[i] << ',';

        if (forwardRunResult.miValues[i] != 0.0)
            output << forwardRunResult.miValues[i] << ',';
        else
            output << '-' << ',';

        if (forwardRunResult.riValues[i] != 0.0)
            output << forwardRunResult.riValues[i] << ',';
        else
            output << '-' << ',';

        if (forwardRunResult.phiValues[i] != 0.0)
            output << forwardRunResult.phiValues[i] << ',';
        else
            output << '-' << ',';

        if (forwardRunResult.ciValues[i] != 0.0)
            output << forwardRunResult.ciValues[i] << ',';
        else
            output << '-' << ',';

        if (forwardRunResult.diValues[i] != 0.0)
            output << forwardRunResult.diValues[i] << ',';
        else
            output << '-' << ',';

        output << '\n';
    }

    double y0{ (constants::bigA * step - constants::alpha0 * yValues[1]) / (step * constants::alhpa1 - constants::alpha0) };

    output << "y0 = " << y0 << '\n';
    output << "yi[0] = " << yValues[0] << '\n';
    output << "|y0-yi[0]| = " << std::abs(y0 - yValues[0]) << "\n\n";
}

int main()
{
    std::ofstream output{ "output.csv" };
    auto forwardRunResult{ forwardRun(10) };
    auto yValues{ backwardRun(forwardRunResult, 10) };
    printResults(forwardRunResult, yValues, 10, output);

    forwardRunResult = forwardRun(20);
    yValues = backwardRun(forwardRunResult, 20);
    printResults(forwardRunResult, yValues, 20, output);

    return 0;
}
