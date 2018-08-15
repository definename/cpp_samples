#include "pch.h"

int main(int argc, char* argv[])
{
	try
	{
		std::list<int> l1 = { 1, 2, 99, 12, 43, 221, 87 };
		std::list<int> l2 = { 1, 66, 23, 2, 99, 12, 43, 221, 87 , 999 };
		l1.sort();
		l2.sort();

		std::list<int>::const_iterator it1 = l1.begin();
		for (it1; it1 != l1.end(); ++it1)
		{
			bool put = false;
			std::list<int>::const_iterator it2 = l2.begin();
			for (it2; it2 != l2.end(); ++it2)
			{
				if (*it2 >= *it1)
				{
					l2.insert(it2, *it1);
					put = true;
					break;
				}
			}

			if (!put) {
				l2.push_back(*it1);
			}
		}

		for (const auto& val : l2)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}