#include "pch.h"

enum class Fields
{
	One,
	Two,
	Three
};

template<typename T>
constexpr std::underlying_type_t<T> toUType(T enumerator) noexcept
{
	return static_cast<std::underlying_type_t<T>>(enumerator);
}


int main(int argc, char* argv[])
{
	try
	{
		std::tuple<int, std::string, double> t(std::make_tuple(1, "two", 3.0));
		std::cout << std::get<toUType(Fields::One)>(t) << std::endl;
		std::cout << std::get<toUType(Fields::Two)>(t) << std::endl;
		std::cout << std::get<toUType(Fields::Three)>(t) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}