#ifndef GRAPHS_H
#define GRAPHS_H

#include <array>

enum class GraphType
{
	first,
	second,
};

void makeGraph(float* firstPart, float* secondPart, GraphType graphType, float constant);

void makeUsingEvaluationFunction(float* firstPart, float* secondPart, float constant);
void makeUsingDigitalDifferentialAnalyzer(float* vertices, float constant);

#endif
