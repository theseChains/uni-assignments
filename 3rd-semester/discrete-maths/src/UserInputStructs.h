#ifndef USER_INPUT_STRUCTS_H
#define USER_INPUT_STRUCTS_H

#include "Context.h"

struct VertexCreator
{
	void operator()(Context context);
};

struct VertexChooserForRoutes
{
	void operator()(Context context);
};

struct VertexChooserForDistance
{
	void operator()(Context context);
};

struct VertexRemover
{
	void operator()(Context context);
};

struct MatrixNumberChanger
{
	void operator()(Context context);

	void makeEdge(std::size_t rowIndex, std::size_t columnIndex, EntityList& entityList);
	void removeEdge(std::size_t rowIndex, std::size_t columnIndex, EntityList& entityList);
};

struct AnswerIndicator
{
	void operator()(Context context);
};

struct DistanceSolver
{
	void operator()(Context context);
};

struct NumberOfRoutesSolver
{
	void operator()(Context context);
};

#endif
