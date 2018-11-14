#include "pch.h"
#include "Test.h"

int main(int argc, char* argv[])
{
    {
        emulator::Test test1;
        std::cout << test1.Do() << std::endl;
        std::cout << test1.Do() << std::endl;
    }

    {
        emulator::Test test2;
        std::cout << test2.Do() << std::endl;
        std::cout << test2.Do() << std::endl;
    }
	return 0;
}