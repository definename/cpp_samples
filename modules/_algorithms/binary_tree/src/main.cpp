#include "pch.h"
#include "Tree.h"

/* Reductions //////////////////////////////////////////////////////////////////////////
BFS - Breadth First Search.
DFS - Depth First Search.
//////////////////////////////////////////////////////////////////////////*/


int main()
{
	try
	{
		const int size = 11;
		int values[size] = {8, 20, 15, 5, 2, 1, 6, 21, 25, 19, 16};

		//////////////////////////////////////////////////////////////////////////
		// Task #1
		//

		//! Demonstrates functionality to insert nodes.
		TreePtr treePtr(new Tree());
		std::cout << "Insert..." << std::endl;
		for (size_t index = 0; index != size; ++index)
		{
			treePtr->Insert(values[index]);
		}
		treePtr->Print();
		std::cout << std::endl;

		//! Demonstrates functionality to calculate tree height.
		std::cout << "Height..." << std::endl;
		std::cout << "Maximum tree height: " << treePtr->GetMaxHeight() << std::endl;
		std::cout << std::endl;

		//! Demonstrates functionality to delete node given value.
		std::cout << "Delete..." << std::endl;
		int del = 8;
		treePtr->Delete(del);
		treePtr->Print();
		std::cout << std::endl;

		//! Demonstrates functionality to find node with given value.
		std::cout << "Find..." << std::endl;
		int val = 5;
		TreeNode::TreeNodePtr res = treePtr->Find(val);
		if (!res)
			std::cout << "There is no node with value: " << val << std::endl;
		else
			std::cout << "Found value: " << res->value_ << std::endl;

		std::cout << std::endl;

		//////////////////////////////////////////////////////////////////////////
		// Task #2
		//

		//! Demonstrates BFS functionality.
		std::cout << "Breadth First Search... Discover All nodes." << std::endl;
		treePtr->BFS();
		std::cout << std::endl;

		//! Demonstrates DFS functionality.
		std::cout << "Depth First Search... Discover All nodes." << std::endl;
		treePtr->DFS();
		std::cout << std::endl;

		//////////////////////////////////////////////////////////////////////////
		// Task #3
		//

		//! Demonstrates Dijkstra functionality.
		std::cout << "Dijkstra..." << std::endl;
		treePtr->Dijkstra();
		treePtr->Print();
		std::cout << std::endl;

		//! Demonstrates Bellman-Ford functionality.
		std::cout << "Bellman-Ford..." << std::endl;
		treePtr->BellmanFord();
		treePtr->Print();
		std::cout << std::endl;

		//! Demonstrates Floyd-Warshall functionality.
		std::cout << "Floyd-Warshall..." << std::endl;
		treePtr->FloydWarshall();
		std::cout << std::endl;

		//////////////////////////////////////////////////////////////////////////
		// Task #4
		//

		//! Demonstrates Prim algorithm.
		std::cout << "Prim..." << std::endl;
		treePtr->Prim();
		treePtr->Print();
		std::cout << std::endl;

		//! Demonstrates Kruskal.
		std::cout << "Kruskal..." << std::endl;
		treePtr->Kruskal();
		treePtr->Print();

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	std::cin.get();
	return 0;
}