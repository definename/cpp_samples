#include "pch.h"

void InsertIterator(const std::vector<int>& v);
void StreamIterator(const std::vector<int>& v);

void main(int argc, char* argv[])
{
	try
	{
		std::vector<int> vec;
		for (int i = 0; i != 10; i++)
		{
			vec.push_back(i);
		}

		StreamIterator(vec);
		InsertIterator(vec);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}

void StreamIterator(const std::vector<int>& v)
{
	std::cout << "Stream iterator: ";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void InsertIterator(const std::vector<int>& v)
{
	std::cout << "Insert iterator" << std::endl;
	std::vector<int> v2;
	std::back_insert_iterator<std::vector<int>> inserter(v2);
	std::remove_copy_if(v.begin(), v.end(), inserter, std::bind2nd(std::equal_to<int>(), 8));

	std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
}