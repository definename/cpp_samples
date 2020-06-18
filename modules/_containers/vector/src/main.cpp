#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <sstream>
#include <functional>

template <typename T>
void PRINT_COLLECTION(const T& cont) {
	std::ostringstream ss;
	for (const auto& val : cont) {
		ss << val << " ";
	}
	std::cout << ss.str() << std::endl;
}

using Coll = std::vector<int>;

int main()
{
	Coll coll;

	//////////////////////////////////////////////////////////////////////////
	// Copy
	std::list<int> src({ 1, 2, 4, 46, -2, 234, 90 });
	std::copy(src.begin(), src.end(), std::back_inserter(coll));
	PRINT_COLLECTION(coll);

	//////////////////////////////////////////////////////////////////////////
	// Sort

	{
		std::cout << "Sort..." << std::endl;
		std::sort(coll.begin(), coll.end(), std::less<Coll::value_type>());
		PRINT_COLLECTION(coll);
		std::sort(coll.begin(), coll.end(), std::bind(std::less<Coll::value_type>(), std::placeholders::_1, std::placeholders::_2));
		PRINT_COLLECTION(coll);

		std::sort(coll.begin(), coll.end(), std::greater<Coll::value_type>());
		PRINT_COLLECTION(coll);
		std::sort(coll.begin(), coll.end(), std::bind(std::less<Coll::value_type>(), std::placeholders::_2, std::placeholders::_1));
		PRINT_COLLECTION(coll);
	}

	//////////////////////////////////////////////////////////////////////////
	// Insert

	{
		std::cout << "Insert..." << std::endl;
		Coll::iterator it = std::find(coll.begin(), coll.end(), 46);
		coll.insert(it, 999);
		PRINT_COLLECTION(coll);

		std::sort(coll.begin(), coll.end());
		auto insertSorted = [](Coll& coll, const Coll::value_type& val) -> void
		{
			coll.insert(std::lower_bound(coll.begin(), coll.end(), val), val);
		};
		insertSorted(coll, 5);
		PRINT_COLLECTION(coll);
	}

	//////////////////////////////////////////////////////////////////////////
	// Remove

	{
		std::cout << "Remove..." << std::endl;
		auto it = std::remove_if(
			coll.begin(),
			coll.end(),
			[](const Coll::value_type& val) ->bool { return  val % 2 != 0; });
		coll.erase(it, coll.end());
		coll.shrink_to_fit();
		PRINT_COLLECTION(coll);

		auto quickRemove = [](Coll& coll, const std::size_t index) -> void
		{
			coll[index] = std::move(coll.back());
			coll.pop_back();
		};
		quickRemove(coll, 0);
		PRINT_COLLECTION(coll);
	}
	return EXIT_SUCCESS;
}