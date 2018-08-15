#include "pch.h"

struct Obj
{
	void Print() {
		std::cout << name_ << std::endl;
	}
	void Set(const std::string& name) {
		name_ = name;
	}
	std::string name_;
};

int main(int argc, char* argv[])
{
	try
	{
		Obj obj;
		std::mem_fn(&Obj::Set)(obj, "Name");

		std::deque<Obj> coll(10, obj);

		std::for_each(coll.begin(), coll.end(), std::mem_fn(&Obj::Print));
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}