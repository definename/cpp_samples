#include "pch.h"

class Environment
{
	//! Enables access to private data members.
	friend class Deleter;

	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Environment()
		: col_(10) {
		int start = 0;
		std::generate(
			col_.begin(),
			col_.end(),
			[&start]() -> int {
			return (++start)++;
		});
	}
	//! Destructor.
	~Environment() = default;

	//
	// Private data members.
	//
private:
	//! Collection.
	std::vector<int> col_;
};

class Deleter
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Deleter() = default;
	//! Destructor.
	~Deleter() = default;

	//
	// Public interface.
	//
public:
	//! Function call operator.
	void operator()(Environment* env) {
		for (const auto& val : env->col_) {
			std::cout << val << std::endl;
		}
		env->col_.clear();
	}
};

void main(int argc, char* argv[])
{
	try {
		std::cout << "in" << std::endl;
		std::shared_ptr<Environment> env(new Environment, Deleter());
		std::cout << "out" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}