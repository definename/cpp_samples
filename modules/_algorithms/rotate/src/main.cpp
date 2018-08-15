#include "pch.h"

int main()
{
	std::vector<int> v;
	for (int i = 0; i != 3; i++)
	{
		v.push_back(i);
		v.push_back(i);
		v.push_back(i);
	}
	for (const auto& val : v)
	{
		std::cout << val;
	}
	std::cout << std::endl;

	std::rotate(v.rbegin(), v.rbegin() + v.size() / 2, v.rend());
	for (const auto& val : v)
	{
		std::cout << val;
	}
	std::cout << std::endl;

	return 0;
}