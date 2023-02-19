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
void makeSecondGraph(float* vertices, const std::array<float, 4>& constants);
void makeThirdGraph(float* vertices, const std::array<float, 4>& constants);
void makeFourthGraph(float* xVertices, float* yVertices, const std::array<float, 4>& constants);
void makeFifthGraph(float* xVertices, float* yVertices, const std::array<float, 4>& constants);
void makeSixthGraph(float* vertices, const std::array<float, 4>& constants);

#endif
