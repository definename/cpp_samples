#include <list>
#include <iostream>
#include <sstream>

template <typename T>
void PRINT_COLLECTION(const T& cont) {
	std::ostringstream ss;
	for (const auto& val : cont) {
		ss << val << " ";
	}
	std::cout << ss.str() << std::endl;
}

using IntList = std::list<int>;

int main()
{
	IntList coll1{ 1, 2, 99, 12, 43, 221, 87 };
	IntList coll2{ 1, 66, 23, 2, 99, 12, 43, 221, 87 , 999 };


	//////////////////////////////////////////////////////////////////////////
	// Merge

	std::cout << "Merge..." << std::endl;

	coll1.sort();
	coll2.sort();

	PRINT_COLLECTION(coll1);
	PRINT_COLLECTION(coll2);

	for (const auto &val : coll2) {
		auto it = std::lower_bound(coll1.begin(), coll1.end(), val);
		coll1.insert(it, val);
	}

	PRINT_COLLECTION(coll1);
	return EXIT_SUCCESS;
}