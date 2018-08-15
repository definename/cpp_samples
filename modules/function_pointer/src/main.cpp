#include "pch.h"

//! Function pointer with one param.
int (*Func1) (const int&);
//! Function pointer type.
typedef void (*Func2) (const int&);
//! Function pointer type with c++11
using Func3 = void (*)(const std::string&);

//! Test function1.
int Test1(const int& val);
//! Test function2.
void Test2(const int& val);
//! Test function3.
void Test3(Func2 f);
//! Test function4
void Test4(void f(const int&));

void main(int argc, char* argv[])
{
	Func1 = &Test1;
	std::cout << Func1(10) << std::endl;
	std::cout << (*Func1)(10) << std::endl;

	Func2 f = &Test2;
	f(100);

	Func3 f3 = [](const std::string& data) -> void {
		std::cout << data << std::endl;
	};
	f3("data");

	Test3(&Test2);
	Test4(Test2);
}

int Test1(const int& val)
{
	return val;
}

void Test2(const int& val)
{
	std::cout << val << std::endl;
}

void Test3(Func2 f)
{
	f(1000);
}

void Test4(void f(const int&))
{
	f(2000);
}