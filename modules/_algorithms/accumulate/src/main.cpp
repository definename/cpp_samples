#include "pch.h"

int arithmeticMean(const std::vector<int>& v);
double geometricMean(const std::vector<int>& v);
double geometricMeanFunctor(const std::vector<int>& v);

int predicat(int num1, int num2)
{
	return (num1 * num2);
}

int main()
{
	std::vector<int> vec;
	for (int i = 1; i != 10; ++i)
	{
		vec.push_back(i);
	}

	std::cout << "arithmetic mean: " << arithmeticMean(vec) << std::endl;
	std::cout << "geometric mean: " << geometricMean(vec) << std::endl;
	std::cout << "geometric mean functor: " << geometricMeanFunctor(vec) << std::endl;

	return 0;
}

int arithmeticMean(const std::vector<int>& v)
{
	int sum = std::accumulate(v.begin(), v.end(), 0);
	return (sum / v.size());
}

double geometricMean(const std::vector<int>& v)
{
	double mult = std::accumulate(v.begin(), v.end(), 1, predicat);
	return (std::pow(mult, 1.0 / v.size()));
}

double geometricMeanFunctor(const std::vector<int>& v)
{
	double mult = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
	return (std::pow(mult, 1.0 / v.size()));
}