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

class IntSequence
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	IntSequence(const int val)
		: val_(val) {
	}

	//
	// Public interface.
	//
	int operator()() {
		return val_++;
	}

	//
	// Private data members.
	//
private:
	//! Value.
	int val_;
};

int main(int argc, char* argv[])
{
	try
	{
		std::list<int> coll;

		IntSequence seq(1);
		std::generate_n<std::back_insert_iterator<decltype(coll)>, int, IntSequence&>(
			std::back_inserter(coll), 4, seq);

		PRINT_COLLECTION(coll);

		std::generate_n(std::back_inserter(coll), 4, IntSequence(100));

		PRINT_COLLECTION(coll);

		std::generate_n(std::back_inserter(coll), 4, seq);

		PRINT_COLLECTION(coll);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}