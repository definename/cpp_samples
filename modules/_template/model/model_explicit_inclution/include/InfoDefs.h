#pragma once

namespace emulator
{

// Implementation.
template <typename T>
void PrintInfo(T const& x)
{
	std::cout << typeid(x).name() << std::endl;
}

}	// emulator