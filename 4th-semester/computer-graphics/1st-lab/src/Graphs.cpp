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
			makeSecondGraph(vertices, constants);
			break;
		}
		case GraphType::third:
		{
			makeThirdGraph(vertices, constants);
			break;
		}
		case GraphType::fourth:
		{
			makeFourthGraph(xVertices, vertices, constants);
			break;
		}
		case GraphType::fifth:
		{
			makeFifthGraph(xVertices, vertices, constants);
			break;
		}
		case GraphType::sixth:
		{
			makeSixthGraph(vertices, constants);
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
			constants[0] = 10.0f;
			constants[1] = 5.0f;
			break;
		}
		case GraphType::third:
		{
			constants[0] = -2.0f;
			constants[1] = 20.0f;
			break;
		}
		case GraphType::fourth:
		{
			constants[0] = 2.0f;
			constants[1] = 3.0f;
			break;
		}
		case GraphType::fifth:
		{
			constants[0] = 0.5f;
			constants[1] = 0.3f;
			constants[2] = 2.0f;
			break;
		}
		case GraphType::sixth:
		{
			constants[0] = 4.0f;
			constants[1] = 8.0f;
			constants[2] = 5.0f;
			constants[3] = 1.0f;
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

void makeSecondGraph(float* vertices, const std::array<float, 4>& constants)
{
	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		vertices[i++] = x;
		vertices[i] = sin(constants[0] * x) * cos(constants[1] * x);
	}
}

void makeThirdGraph(float* vertices, const std::array<float, 4>& constants)
{
	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		vertices[i++] = x;
		vertices[i] = pow(std::numbers::e, constants[0] * x) * sin(constants[1] * x);
	}
}

void makeFourthGraph(float* xVertices, float* yVertices, const std::array<float, 4>& constants)
{
	for (int i{ 1 }; i < 2000; i += 2)
	{
		float y{ (i - 1000.0f) / 1000.0f };
		xVertices[i] = y;
		xVertices[i - 1] = cos(constants[0] * y);
	}

	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		yVertices[i++] = x;
		yVertices[i] = sin(constants[0] * x);
	}
}

void makeFifthGraph(float* xVertices, float* yVertices, const std::array<float, 4>& constants)
{
	for (int i{ 1 }; i < 2000; i += 2)
	{
		float y{ (i - 1000.0f) / 1000.0f };
		xVertices[i] = y;
		xVertices[i - 1] = constants[0] * cos(constants[2] * y);
	}

	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		yVertices[i++] = x;
		yVertices[i] = constants[1] * sin(constants[2] * x);
	}
}

void makeSixthGraph(float* vertices, const std::array<float, 4>& constants)
{
	for (int i{ 0 }; i < 2000; ++i)
	{
		float x{ (i - 1000.0f) / 1000.0f };
		vertices[i++] = x;
		vertices[i] = constants[0] * pow(x, 3) + constants[1] * pow(x, 2) + constants[2] * x +
				constants[3];
	}
}
