#include "pch.h"

void print(const std::vector<int>& v);

int main()
{
	std::vector<int> vecOne, vecTwo;

	for(int i = 0; i != 10; i++)
	{
		vecOne.push_back(i);
	}

	////////////////////////////////////////////////////////////////////////// copy
	vecTwo.resize(vecOne.size());
	std::copy(vecOne.begin(), vecOne.end(), vecTwo.begin());
	print(vecTwo);

	////////////////////////////////////////////////////////////////////////// copy_backward
	vecOne.clear();
	vecOne.resize(vecTwo.size());
	std::copy_backward(vecTwo.begin(), vecTwo.begin() + 5, vecOne.end());
	print(vecOne);

	return 0;
}

void print(const std::vector<int>& v)
{
	std::for_each(v.begin(), v.end(), [](const int& i){ std::cout << i; });
	std::cout << std::endl;
}