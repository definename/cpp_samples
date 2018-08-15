#include "pch.h"

template <typename T>
void PRINT_MAP(const T& cont)
{
	std::ostringstream ss;
	for (const auto& [key, value] : cont) {
		ss << key << " " << value << " ";
	}
	logger::log->info("{} ", ss.str());
}

int main()
{
	logger::InitializeLog("console");

	//////////////////////////////////////////////////////////////////////////
	// Accumulate values
	{
		logger::log->trace("Accumulate values...");
		using Coll = std::map<std::string, int>;

		Coll coll({
			{ "one", 1 },
			{ "two", 2 },
			{ "three", 3 }
			});

		auto op = std::bind(
			std::plus<int>(),
			std::placeholders::_1,
			std::bind(&Coll::value_type::second, std::placeholders::_2));

		logger::log->info("Value sum: ", std::accumulate(coll.begin(), coll.end(), 0, op));
	}

	//////////////////////////////////////////////////////////////////////////
	// Change keys
	{
		logger::log->trace("Change keys...");
		using Coll = std::map<int, std::string>;

		Coll coll {
			{ 1, "Mario" },
			{ 2, "Luigi" },
			{ 3, "Bowser"},
			{ 4, "Toad" }
		};

		PRINT_MAP<Coll>(coll);

		Coll::node_type first = coll.extract(coll.begin());
		Coll::node_type last = coll.extract(--coll.end());

		std::swap(first.key(), last.key());

		coll.insert(std::move(first));
		coll.insert(std::move(last));

		PRINT_MAP<Coll>(coll);
	}

	logger::UninitializeLog();


	return 0;
}