#include "pch.h"

class Min
{
public:
	Min()
		: min_(-1)
		, first_(true)
	{ };

	void operator() (int el)
	{
		if (first_)
		{
			first_ = false;
			min_ = el;
		}
		else if (min_ > el)
		{
			min_ = el;
		}
	};

public:
	bool first_;
	int min_;
};

void main(int argc, char* argv[])
{
	try
	{
		std::vector<int> vec;
		for (int i = 0; i != 10; i++) {
			vec.push_back(i);
		}

		Min min = std::for_each(vec.begin(), vec.end(), Min());
		std::cout << "MIN: " << min.min_ << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}