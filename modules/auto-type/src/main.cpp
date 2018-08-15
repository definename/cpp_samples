#include "pch.h"

// Forward declaration
template<typename T>
class TD;

void main(int argc, char* argv[])
{
	try
	{
		// with linker - see error list in order to check type:
		const int theAnswer = 10;
		auto x = theAnswer;
		auto y = &theAnswer;

// 		TD<decltype(x)> xType;
// 		TD<decltype(y)> yType;
		
		// stl type info
		std::cout << typeid(x).name() << std::endl;
		std::cout << typeid(y).name() << std::endl;

		// boost type index
		std::cout << boost::typeindex::type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
		std::cout << boost::typeindex::type_id_with_cvr<decltype(y)>().pretty_name() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}