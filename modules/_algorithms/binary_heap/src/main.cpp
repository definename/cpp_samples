#include "pch.h"
#include "BinaryHeap.h"


/*/////////////////////////////////////////////////////////////////////////
1. Отсортировать массив, используя промежуточное представление в виде двоичной кучи.
https://habrahabr.ru/post/112222/
/////////////////////////////////////////////////////////////////////////*/

int main()
{
	try
	{
		srand(time(NULL));

		//! Generates random array.
		std::vector<int> arr;
		std::cout << "Origin: ";
		for (int i = 0; i != 20; ++i)
		{
			int val = rand() % 100 + 1;
			arr.push_back(val);
			std::cout << val << " ";
		}
		std::cout << std::endl;

		//! Heap sort.
		BinaryHeap heap;
		heap.HeapSort(arr);

		//! Print result.
		std::cout << "Sorted: ";
		for (const int& val : arr)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return 0;
}