#include "pch.h"

class Base {
	//
	// Default construction and destruction.
	//
public:
	//! Default constructor.
	Base() = default;
	//! Copy constructor.
	Base(const Base&) = default;
	//! Assignment operator
	Base& operator=(const Base&) = default;
	//! Move copy constructor.
	Base(Base&& rhs)
		: i_(std::move(rhs.i_)) {
	}
	//! Move assignment operator.
	Base& operator=(Base&& rhs) = default;
	//! Destructor.
	virtual ~Base() = default;

	//
	// Construction and destruction.
	//
public:
	//! Initialization list constructor.
	Base(std::initializer_list<int> const& data) {
		for (auto const& val : data) {
			std::cout << val;
		}
		std::cout << std::endl;
	}
	//! Constructor.
	Base(const int& i)
		: i_(i) {
	}
	//! Move constructor.
	Base(int&& i)
		: i_(std::move(i)) {
	}

	//
	// Private interface
	//
public:
	//! int value.
	int i_;
};

int main(int argc, char* argv[])
{
	try
	{
		{
			Base obj{ 1, 1, 1, 1 }; // Obj(std::initializer_list<int> const& data)
			Base obj1(std::move(obj)); // Base(Base&& rhs)
		}

		{
			Base obj(std::move(10)); // call Obj(int&& i)
		}

		{
			Base obj(10); // call Obj(int&& i)
		}

		{
			int i = 10;
			Base obj(i); // Obj(const int& i)
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}