#include "pch.h"
#include "GraphAsAdjacencyList.h"

//////////////////////////////////////////////////////////////////////////
// Implementation of the GraphAsAdjacencyList class.
//

GraphAsAdjacencyList::GraphAsAdjacencyList()
{
	List list0{ { 1, false }, {4, true} };
	List list1{ { 0, false }, { 4, false }, { 3, false }, { 2, true } };
	List list2{ { 1, false }, { 3, true } };
	List list3{ { 4, false }, { 1, false }, { 2, true } };
	List list4{ { 0, false }, { 1, false }, { 3, true } };

	list_ = { list0, list1, list2, list3, list4 };

	colors_ = { WHITE, WHITE, WHITE, WHITE, WHITE };
}

GraphAsAdjacencyList::~GraphAsAdjacencyList()
{ }

void GraphAsAdjacencyList::Scan(int vertexNum)
{
	int counter = 0;
	
	colors_[vertexNum] = GRAY;
	
	List list = list_[vertexNum];
	do
	{
		if (colors_[list[counter].num] == WHITE)
		{
			Scan(list[counter].num);
		}
	}
	while (list[counter++].last == false);
	
	colors_[vertexNum] = BLACK;

	std::cout << vertexNum << " ";
}
