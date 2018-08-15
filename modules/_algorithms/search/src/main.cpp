#include "pch.h"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(9);
	vec.push_back(8);
	vec.push_back(8);
	vec.push_back(100);

	//////////////////////////////////////////////////////////////////////////
	std::vector<int>::const_iterator it;
	it = std::min_element(vec.begin(), vec.end());
	std::cout << "Minimum element: " << *it << std::endl;

	//////////////////////////////////////////////////////////////////////////
	it = std::max_element(vec.begin(), vec.end());
	std::cout << "Maximum element: " << *it << std::endl;

	//////////////////////////////////////////////////////////////////////////
	int targets[] = {1000, 2};
	it = std::find_first_of(vec.begin(), vec.end(), targets, targets + sizeof(targets) / sizeof(int));

	if (it == vec.end())
		std::cout << "find_first_of not found" << std::endl;
	else
		std::cout << "find_first_of: " << *it << std::endl;

	//////////////////////////////////////////////////////////////////////////
	int targers1[] = {9, 8};
	it = std::search(vec.begin(), vec.end(), targers1, targers1 + sizeof(targers1) / sizeof(int));

	if (it == vec.end())
		std::cout << "search not found" << std::endl;
	else
		std::cout << "search: " << it - vec.begin() << std::endl;

	//////////////////////////////////////////////////////////////////////////
	std::vector<int> vec1;
	vec1.push_back(8);
	vec1.push_back(8);

	it = std::find_end(vec.begin(), vec.end(), vec1.begin(), vec1.end());

	if (it == vec.end())
		std::cout << "find_end not found" << std::endl;
	else
		std::cout << "find_end: " << *it << std::endl;

	return 0;
}