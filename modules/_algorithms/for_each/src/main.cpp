#include "pch.h"
#include "Types.h"

void printPair(const std::pair<int, int>& el);

int main()
{
	std::map<int, int> myMap;
	myMap.insert(std::make_pair(4, 10));
	myMap.insert(std::make_pair(6, 23));
	myMap.insert(std::make_pair(8, 11110));
	myMap.insert(std::make_pair(2, 2));
	myMap.insert(std::make_pair(1, 1));

	//////////////////////////////////////////////////////////////////////////
	std::for_each(myMap.begin(), myMap.end(), printPair);

	//////////////////////////////////////////////////////////////////////////
	Min min;
	min = std::for_each(myMap.begin(), myMap.end(), min);
	std::cout << "MIN: " <<  min.min << std::endl;

	//////////////////////////////////////////////////////////////////////////
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::transform(vec.begin(), vec.end(), vec.begin(), std::bind2nd(std::plus<int>(), 100));
	std::for_each(vec.begin(), vec.end(), [](const int& el){ std::cout << "res: " << el << std::endl; });
	return 0;
}

void printPair(const std::pair<int, int>& el)
{
	std::cout << "first: " << el.first << " second: " << el.second << std::endl;
}