#include "pch.h"

template <typename T>
void PRINT_COLLECTION(T coll)
{
	for (const auto& val : coll)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::forward_list<int> coll({1, 2, 3, 4, 5, 6, 7, 8, 9});
	PRINT_COLLECTION(coll);

	auto it = coll.insert_after(coll.before_begin(), 100);
	PRINT_COLLECTION(coll);

	return 0;
}