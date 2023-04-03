#ifndef GRAPHS_H
#define GRAPHS_H

#include <array>

enum class GraphType
{
	first,
	second,
};

void makeGraph(float* vertices, GraphType graphType, float constant);

void makeUsingEvaluationFunction(float* vertices, float constant);
void makeUsingDigitalDifferentialAnalyzer(float* vertices, float constant);

#endif
