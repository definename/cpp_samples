#include "pch.h"

struct Obj
{
	~Obj() {
		throw 123;
	}
};

int main(int argc, char* argv[])
{
	std::set_terminate([]() ->void { std::cout << "Oops terminated!!" << std::endl; });
	Obj obj;
}