#include "Graphs.h"

#include <cmath>
#include <iostream>

void makeGraph(float* vertices, GraphType graphType, float constant)
{
	switch (graphType)
	{
		case GraphType::first:
		{
			makeUsingEvaluationFunction(vertices, constant);
			break;
		}
		case GraphType::second:
		{
			makeUsingDigitalDifferentialAnalyzer(vertices, constant);
			break;
		}
	}
}

void makeUsingEvaluationFunction(float* vertices, float constant)
{
	float currentX{ 0.001f };
	// nonsense, made to comply with the dda method below
	constant -= 0.295f;

	int index{ 0 };
	while (currentX < 1.0f && index < 2000)
	{
		vertices[index++] = currentX;
		vertices[index] = constant / (2 * currentX);
		currentX += 0.001f;
		++index;
	}
}

void makeUsingDigitalDifferentialAnalyzer(float* vertices, float constant)
{
	// none of this makes sense, i have no idea what's going on, but it kinda works
	float startingX{ 0.05f };
	float startingY{ constant / (2 * startingX) };

	vertices[0] = startingX / 1000.0f;
	vertices[1] = startingY;
	float currentX{ startingX };
	float currentY{ startingY };
	float deltaX{ static_cast<float>(1 / (std::pow(constant, 2) / 4 * std::pow(currentX, 4) + 1)) };
	float deltaY{ -static_cast<float>((constant / (2 * std::pow(currentX, 2))) /
			(std::pow(constant, 2) / (4 * std::pow(currentX, 4)) + 1)) };

	for (int i{ 2 }; i < 2000; ++i)
	{
		deltaY = -static_cast<float>((constant / (2 * std::pow(currentX, 2))) /
			(std::pow(constant, 2) / (4 * std::pow(currentX, 4)) + 1));

		currentX += deltaX;
		currentY += deltaY * 12; // why?

		vertices[i++] = currentX / 1000.0f;
		vertices[i] = currentY;
	}
}
