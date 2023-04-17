#include "Graphs.h"

#include <cmath>
#include <iostream>

void makeGraph(float* firstPart, float* secondPart, GraphType graphType, float constant)
{
	switch (graphType)
	{
		case GraphType::first:
		{
			makeUsingEvaluationFunction(firstPart, secondPart, constant);
			break;
		}
		case GraphType::second:
		{
			makeUsingDigitalDifferentialAnalyzer(firstPart, constant);
			break;
		}
	}
}

void makeUsingEvaluationFunction(float* firstPart, float* secondPart, float constant)
{
	float currentX{ -1.0f };
	int index{ 0 };
	// doesn't quite work either
	constant -= 0.295f;

	while (currentX < 0.0f && index < 1000)
	{
		firstPart[index++] = currentX;
		firstPart[index] = constant / (2 * currentX);
		currentX += 0.002f;
		++index;
	}

	currentX = 0.001f;
	index = 0;
	while (currentX < 1.0f && index < 1000)
	{
		secondPart[index++] = currentX;
		secondPart[index] = constant / (2 * currentX);
		currentX += 0.002f;
		++index;
	}
}

void makeUsingDigitalDifferentialAnalyzer(float* vertices, float constant)
{
	// yea this doesn't really work, im sorry
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
