#include "pch.h"

//! Checks enum base type.
template <typename T>
bool EnumIsT();

int main(int argc, char* argv[])
{
	const int i = 100;
	std::cout << std::boolalpha << std::is_const<decltype(i)>::value << std::endl;
	
	std::cout << "Type is " << (EnumIsT<unsigned int>() ? "unsigned int" : "not unsigned int") << std::endl;
	std::cout << "Type is " << (EnumIsT<int>() ? "unsigned int" : "not unsigned int") << std::endl;

	return EXIT_SUCCESS;
}

template <typename T>
bool EnumIsT()
{
	enum Type : T {
		Unknown = 0,
		Work
	};

// 	std::underlying_type_t<Type> i;
// 	bool same = std::is_same<int, decltype(i)>::value;

	return std::is_same<unsigned int, std::underlying_type_t<Type>>::value;
}