#ifndef GRAPHS_H
#define GRAPHS_H

#include <array>

enum class GraphType
{
	first,
	second,
	third,
	fourth,
	fifth,
	sixth
};

void makeGraph(float* vertices, GraphType graphType, const std::array<float, 4>& constants,
		float* xVertices);
void setUpConstants(GraphType graphType, std::array<float, 4>& constants);

void makeFirstGraph(float* vertices, const std::array<float, 4>& constants);
void makeSecondGraph(float* vertices);
void makeThirdGraph(float* vertices);
void makeFourthGraph(float* xVertices, float* yVertices);
void makeFifthGraph(float* xVertices, float* yVertices);
void makeSixthGraph(float* vertices);

#endif
