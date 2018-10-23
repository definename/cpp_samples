#include "pch.h"

class A
{
public:
	A() = default;
	~A() = default;

public:
	void Audio() {
		logger::log->info("A");
	}
};

class B : public A
{
public:
	B() = default;
	~B() = default;

public:
	void Audio() {
		A::Audio();
		logger::log->info("B");
	}
};

int main(int argc, char* argv[], char* env[])
{
	int code = 0;
	try
	{
		logger::InitializeLog("console");

		B* b = new B();
		b->Audio();

		A* a = b;
		a->Audio();

		logger::UninitializeLog();
	}
	catch (const spdlog::spdlog_ex& e)
	{
		std::cerr << "spdlog error occurred: " << e.what() << std::endl;
		code = 1;
	}
	catch (const std::exception& e)
	{
		logger::log->error("Error occurred: {}", e.what());
		code = 2;
	}

	return 0;
}