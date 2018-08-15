#include "pch.h"

int main(int argc, char* argv[])
{
	try
	{
		int id = 0;
		auto f = [id]() mutable {
			std::cout << id << std::endl;
			++id;
		};

		f();
		f();
		f();

		std::cout << id << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}