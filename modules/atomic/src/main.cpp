#include "pch.h"

std::atomic<int> data_;

int main(int argc, char* argv[])
{
	try
	{
        data_ = 1;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return 0;
}