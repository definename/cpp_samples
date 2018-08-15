#include "pch.h"

void print(std::vector<int>& vec);

int main()
{
	std::vector<int> vec;
	vec.resize(10);
	std::for_each(vec.begin(), vec.end(), [](int& i) { i = 1; });
	print(vec);

	std::replace(vec.begin(), vec.end(), 1, 99);
	print(vec);
	std::replace_if(vec.begin(), vec.end(), std::bind2nd(std::less<int>(), 100), 0);
	print(vec);

	vec[0] = 10;
	std::vector<int> vec1(vec.size());
	std::replace_copy(vec.begin(), vec.end(), vec1.begin(), 0, 1);
	print(vec1);

	vec1.clear();
	vec1.resize(vec.size());
	std::replace_copy_if(vec.begin(), vec.end(), vec1.begin(), std::bind2nd(std::less<int>(), 10), 9);
	print(vec1);

	return 0;
}

void print(std::vector<int>& v)
{
	std::for_each(v.begin(), v.end(), [](const int& i) { std::cout << i; });
	std::cout << std::endl;
}