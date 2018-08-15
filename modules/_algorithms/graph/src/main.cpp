#include "pch.h"
#include "GraphAsAdjacencyList.h"
#include "GraphAsAdjacencyMatrix.h"

/*/////////////////////////////////////////////////////////////////////////
1. Изобразите граф в виде диаграммы : создайте машинное представление графа в виде 
списочной структуры и в виде матрицы.

2. Составьте и реализуйте алгоритм обхода всех вершин графа 
(выведите на экран спи-сок вершин в порядке обхода графа).
/////////////////////////////////////////////////////////////////////////*/


int main()
{
	try
	{
		GraphAsAdjacencyList graphList;
		std::cout << "Scan Adjacency List Graph: " << std::endl;
		graphList.Scan(0);
		std::cout << std::endl;

		GraphAsAdjacencyMatrix graphMatrix;
		std::cout << "Scan Adjacency Matrix Graph: " << std::endl;
		graphMatrix.Scan(0,5);
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return 0;
}