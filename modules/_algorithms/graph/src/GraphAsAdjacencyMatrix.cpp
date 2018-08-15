#include "pch.h"
#include "GraphAsAdjacencyMatrix.h"

//////////////////////////////////////////////////////////////////////////
// Implementation of the GraphAsAdjacencyMatrix class.
//

GraphAsAdjacencyMatrix::GraphAsAdjacencyMatrix()
{
	matrix_ =
	{
		{ 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 0, 1 },
		{ 1, 1, 0, 1, 0 }
	};

	colors_ = { WHITE, WHITE, WHITE, WHITE, WHITE };
}

GraphAsAdjacencyMatrix::~GraphAsAdjacencyMatrix()
{ }

void GraphAsAdjacencyMatrix::Scan(int vertexNum, int vertexCount)
{
	int counter = 0;

	colors_[vertexNum] = GRAY;

	for (int i = 0; i < vertexCount; i++)
	{
		if (matrix_[vertexNum][i] > 0 && colors_[i] == WHITE)
		{
			Scan(i, vertexCount);
		}
	}

	colors_[vertexNum] = BLACK;

	std::cout << vertexNum << " ";
}