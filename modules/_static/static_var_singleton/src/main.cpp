#include "pch.h"
#include "Test.h"

int main(int argc, char* argv[])
{
	auto& test = emulator::Test::GetInstance();

	std::cout << "NG: " << std::boolalpha << test.IsNG() << std::endl;
	test.SetNG(true);
	std::cout << "NG: " << std::boolalpha << test.IsNG() << std::endl;

	return 0;
}