#include "pch.h"

int main(int argc, char* argv[])
{
	try
	{
		int a = 1;
		int b = 2;
		int c = 3;

		std::reference_wrapper<int> refs[] = { a, b, c };
		for (int& val : refs)
		{
			val += 1;
		}

		std::cout << "Wrapper: " << std::endl;
		for (const auto& val : refs)
		{
			std::cout << val << std::endl;
		}

		std::cout << "Origin: " << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}