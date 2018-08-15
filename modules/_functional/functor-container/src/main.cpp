#include "pch.h"

struct Functor
{
	std::string operator()(const std::string& val)
	{
		return std::string(val).append("Functor");
	}
};

template <typename T>
struct Functor1
{
	T operator()(const T& val)
	{
		return std::string(val).append("Functor template");
	}
};

struct Functor2
{
	template <typename T>
	T operator()(const T& val)
	{
		return std::string(val).append("Functor template2");
	}
};

std::string TestFunc(const std::string& val)
{
	return std::string(val).append("Function");
}

using FunctorType = std::function<std::string(const std::string&)>;

int main(int argc, char* argv[])
{
	try
	{
		std::vector<FunctorType> vec;
		vec.push_back(TestFunc);
		vec.push_back(Functor{});
		vec.push_back(Functor1<std::string>{});
		vec.push_back(Functor2{});
		auto f = [](const std::string& val) -> std::string 
		{
			return std::string(val).append("Lambda");
		};
		vec.push_back(f);

		for (const auto& val : vec)
		{
			std::cout << val("Test ") << std::endl;
		}

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}