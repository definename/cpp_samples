#include "pch.h"

struct MeanValue
{
	MeanValue()
		: num_(0)
		, sum_(0)
	{ }

	void operator()(const int elem)
	{
		num_++;
		sum_ += elem;
	}

	int Value() const
	{
		return sum_ / num_;
	}

	int num_;
	int sum_;
};

int main(int argc, char* argv[])
{
	try
	{
		std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		MeanValue mean = for_each(vec.begin(), vec.end(), MeanValue());
		std::cout << mean.Value() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}