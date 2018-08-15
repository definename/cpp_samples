#include "pch.h"

template <typename T>
void PRINT_COLLECTION(T coll)
{
	for (const auto& val : coll)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

struct ObjCriterion
{
	bool operator()(const int& value1, const int& value2)
	{
		return value1 > value2;
	}
};

int main(int argc, char* argv[])
{
	try
	{
		std::set<int, ObjCriterion> coll;
		for (int i = 0; i != 10; ++i)
		{
			coll.emplace(i * 10);
		}

		PRINT_COLLECTION(coll);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}