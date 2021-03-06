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

#include <chrono>
#include <list>
#include <cassert>
#include <cstdlib>

void check_time_to_iterate_vector_and_list(const int test_size = 10000000) {
	std::cout << "Test on:" << test_size << " elements" << std::endl;
	std::vector<int> test_vec;
	std::list<int> test_list;

	for (int i = 0; i < test_size; ++i) {
		int gen = rand();
		test_vec.push_back(gen);
		test_list.push_back(gen);
	}
	std::sort(test_vec.begin(), test_vec.end());
	test_list.sort();

	long long int res_list = 0;
	auto start = std::chrono::system_clock::now();
	for (const auto& val: test_list) {
		res_list += val;
	}
	auto stop = std::chrono::system_clock::now();
	auto list_tick_count = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
	std::cout << "List tick result:" << list_tick_count << std::endl;

	long long int res_vec = 0;
	start = std::chrono::system_clock::now();
	for (const auto& val: test_vec) {
		res_vec += val;
	}
	stop = std::chrono::system_clock::now();
	auto vec_tick_count = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
	std::cout << "Vector tick result:" << vec_tick_count << std::endl;

	assert(res_vec == res_list);
	std::cout << ((list_tick_count > vec_tick_count) ? "Vector" : "List") << " won!!" << std::endl;
}

int main()
{
	check_time_to_iterate_vector_and_list();

	Coll coll;

	/* Copy... */
	std::list<int> src({ 1, 2, 4, 46, -2, 234, 90 });
	std::copy(src.begin(), src.end(), std::back_inserter(coll));
	PRINT_COLLECTION(coll);

	/* Sort... */
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

	/* Insert...*/
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


	/* Remove... */
	{
		std::cout << "Remove..." << std::endl;
		// 1
		auto pred = [](const Coll::value_type& val) -> bool { return  val % 2 != 0; };
		coll.erase(std::remove_if(coll.begin(), coll.end(), pred), coll.end());
		coll.shrink_to_fit();
		PRINT_COLLECTION(coll);

		// 2
		auto quickRemove = [](Coll& coll, const std::size_t index) -> void
		{
			coll[index] = std::move(coll.back());
			coll.pop_back();
		};
		quickRemove(coll, 0);
		PRINT_COLLECTION(coll);
	}

	/* Find missed from sequence */
	{
		std::cout << "Find missed from sequence..." << std::endl;
		Coll coll = {1, 2, 3, 6, 7, 7, 4, 2};
		Coll tmp_coll(coll.size() + 1);
		std::generate(tmp_coll.begin(), tmp_coll.end(), [](){ static int i = 0; return i++; });
		for (const auto& val: coll) {
			tmp_coll[val] = 0;
		}
		auto g = [](const int& val){ return val == 0; };
		tmp_coll.erase(std::remove_if(tmp_coll.begin(), tmp_coll.end(), g), tmp_coll.end());
		PRINT_COLLECTION(tmp_coll);
	}

	return EXIT_SUCCESS;
}