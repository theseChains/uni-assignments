#include "Graphs.h"

#include <cmath>
#include <numbers>

void makeGraph(float* vertices, GraphType graphType, const std::array<float, 4>& constants,
		float* xVertices = nullptr)
{
	switch (graphType)
	{
		case GraphType::first:
		{
			makeFirstGraph(vertices, constants);
			break;
		}
		case GraphType::second:
		{
			makeSecondGraph(vertices);
			break;
		}
		case GraphType::third:
		{
			makeThirdGraph(vertices);
			break;
		}
		case GraphType::fourth:
		{
			makeFourthGraph(xVertices, vertices);
			break;
		}
		case GraphType::fifth:
		{
			makeFifthGraph(xVertices, vertices);
			break;
		}
		case GraphType::sixth:
		{
			makeSixthGraph(vertices);
			break;
		}
	}
}

void setUpConstants(GraphType graphType, std::array<float, 4>& constants)
{
	switch (graphType)
	{
		case GraphType::first:
		{
			constants[0] = 10.0f;
			break;
		}
		case GraphType::second:
		{
			break;
		}
		case GraphType::third:
		{
			break;
		}
		case GraphType::fourth:
		{
			break;
		}
		case GraphType::fifth:
		{
			break;
		}
		case GraphType::sixth:
		{
			break;
		}
	}
}

void makeFirstGraph(float* vertices, const std::array<float, 4>& constants)
{
	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		vertices[i++] = x;
		vertices[i] = sin(constants[0] * x) / (constants[0] * x);
	}
}

void makeSecondGraph(float* vertices)
{
	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		vertices[i++] = x;
		vertices[i] = sin(10 * x) * cos(5 * x);
	}
}

void makeThirdGraph(float* vertices)
{
	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		vertices[i++] = x;
		vertices[i] = pow(std::numbers::e, -2 * x) * sin(20 * x);
	}
}

void makeFourthGraph(float* xVertices, float* yVertices)
{
	for (int i{ 1 }; i < 2000; i += 2)
	{
		float y{ (i - 1000.0f) / 1000.0f };
		xVertices[i] = y;
		xVertices[i - 1] = cos(2 * y);
	}

	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		yVertices[i++] = x;
		yVertices[i] = sin(3 * x);
	}
}

void makeFifthGraph(float* xVertices, float* yVertices)
{
	for (int i{ 1 }; i < 2000; i += 2)
	{
		float y{ (i - 1000.0f) / 1000.0f };
		xVertices[i] = y;
		xVertices[i - 1] = 0.5f * cos(2.0f * y);
	}

	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		yVertices[i++] = x;
		yVertices[i] = 0.3f * sin(3 * x);
	}
}

void makeSixthGraph(float* vertices)
{
	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		vertices[i++] = x;
		vertices[i] = 4 * pow(x, 3) + 8 * pow(x, 2) + 5 * x + 1;
	}
}
