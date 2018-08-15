#include "pch.h"

int _tmain(int argc, TCHAR* argv[])
{
start:
	_tcout << "Program is running..." << std::endl;

	int exit = 0;
	_tcout << "exit? (0 - exit, 1 - goto)" << std::endl;
	_tcin >> exit;
	if (exit != 0)
		goto start;

	return EXIT_SUCCESS;
}