#include "pch.h"

template <typename T>
void PRINT_COLLECTION(const T& cont)
{
	std::ostringstream ss;
	for (const auto& val : cont) {
		ss << val << " ";
	}
	logger::log->info("{} ", ss.str());
}

using Coll = std::list<int>;

int main()
{
	logger::InitializeLog("console");

	Coll coll1 = { 1, 2, 99, 12, 43, 221, 87 };
	Coll coll2 = { 1, 66, 23, 2, 99, 12, 43, 221, 87 , 999 };


	//////////////////////////////////////////////////////////////////////////
	// Merge

	logger::log->trace("Merge...");

	coll1.sort();
	coll2.sort();

	PRINT_COLLECTION(coll1);
	PRINT_COLLECTION(coll2);

	for (const auto &val : coll2) {
		coll1.insert(std::lower_bound(coll1.begin(), coll1.end(), val), val);
	}

	PRINT_COLLECTION(coll1);



	logger::UninitializeLog();

	return 0;
}