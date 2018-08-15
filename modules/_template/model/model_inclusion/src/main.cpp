#include "pch.h"
#include "Info.h"

int main(int argc, char* argv[])
{
	double x(10);
	emulator::PrintInfo<double>(x);

	return EXIT_SUCCESS;
}