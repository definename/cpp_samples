#include "pch.h"

void BubbleSort(int* const arr, const int size);

void main(int argc, char* argv[])
{
	try
	{
		int arr[] = {1, 4, 2, 5, 67, 7, 4, 8, 9, 3};
		const int size = sizeof arr / sizeof arr[0];

		std::cout << "In: ";
		for (int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		BubbleSort(arr, size);

		std::cout << "Out: ";
		for (int i = 0; i < size; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}

void BubbleSort(int* const arr, const int size)
{
	for (int pass = 0; pass < size; ++pass)
	{
		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
			}
		}
	}
}