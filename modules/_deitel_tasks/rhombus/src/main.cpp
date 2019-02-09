#include "pch.h"

int main(int argc, char* argv[])
{
	int width = 9; // width should always be odd number
	int height = width - 2;
	for (int i = 1; i <= height; i += 2)
	{
		int space = (width - i) / 2;
		for (int s = 1; s <= space; ++s)
		{
			std::cout << "-";
		}
		for (int a = 1; a <= i; ++a)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	for (int w = 1; w <= width; ++w)
	{
		std::cout << "*";
	}
	std::cout << std::endl;

	for (int i = height; i >= 0; i -= 2)
	{
		int space = (width - i) / 2;
		for (int s = 1; s <= space; ++s)
		{
			std::cout << "-";
		}
		for (int a = 1; a <= i; ++a)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	return 0;
}