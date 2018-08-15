#include "pch.h"
#include "Test.h"

int main(int argc, char* argv[])
{
    {
        emulator::Test test;
        std::cout << test.Do() << std::endl;
        std::cout << test.Do() << std::endl;
    }

    {
        emulator::Test test;
        std::cout << test.Do() << std::endl;
        std::cout << test.Do() << std::endl;
    }
	return 0;
}