#pragma once

#include <iostream>
#include <typeinfo>

namespace emulator
{

// Declaration.
template <typename T>
void PrintInfo(T const& x);


// Implementation.
template <typename T>
void PrintInfo(T const& x)
{
	std::cout << typeid(x).name() << std::endl;
}

}	// emulator