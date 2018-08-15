#include "pch.h"

int main(int argc, char* argv[])
{
	//////////////////////////////////////////////////////////////////////////
	// These two expression are same
	//////////////////////////////////////////////////////////////////////////

	std::cout << std::numeric_limits<unsigned int>::max() - 25u << std::endl;
	std::cout << 25u - 50 << std::endl;
	std::cout << 50 - 25u << std::endl;

	return 0;
}