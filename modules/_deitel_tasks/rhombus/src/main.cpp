#include "pch.h"

int main(int argc, char* argv[])
{
	std::cout << argv[0] << std::endl;
	if (argc > 1) {
		std::cout << argv[1] << std::endl;
	}

	int width = 0; // width should always be odd number
	std::cout << "Enter max width: ";
	std::cin >> width;
	if (width % 2 == 0 || width == 0 || width < 0)
	{
		std::cout << "Incorrect number was given" << std::endl;
		return 1;
	}

	int maxStar = width - 2;
	for (int i = 1; i <= maxStar; i += 2)
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

	for (int i = maxStar; i >= 0; i -= 2)
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
