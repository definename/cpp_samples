#include "pch.h"
#include "fibit.h"

void Fibonacci(const int num);

void main(int argc, char* argv[])
{
	try
	{
		Fibonacci(10);

		for (size_t i : fibrange(10)) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}

void Fibonacci(const int num)
{
	int a = 0;
	int b = 1;
	for (int i = 0; i < num; ++i)
	{
		if (i == 0)
		{
			std::cout << a << " ";
		}
		else if (i == 1)
		{
			std::cout << b << " ";
		}
		else
		{
			int temp = b;
			b += a;
			a = temp;

			std::cout << b << " ";
		}
	}
	std::cout << std::endl;
}