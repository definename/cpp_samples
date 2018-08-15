#include "pch.h"

void Foo(int* ptr);
void FooPtr(std::shared_ptr<int> smartPtr);

void main(int argc, char* argv[])
{
	try
	{
		//////////////////////////////////////////////////////////////////////////
		// Raw pointer.

		int y = 5;
		int* yPtr = &y;

		std::cout << yPtr << std::endl;
		std::cout << &y << std::endl;
		std::cout << *yPtr << std::endl;
		Foo(&y);
		std::cout << y << std::endl;

		//////////////////////////////////////////////////////////////////////////
		// Different const raw pointers.
		{
			int* ptr1;
			const int* ptr2;
			int* const ptr3 = new int(3);
			const int* const ptr4 = new int(4);
		}

		//////////////////////////////////////////////////////////////////////////
		// Shared ptr as parameter
		{
			int* ptr = new int(10);
			FooPtr(std::shared_ptr<int>(ptr));
			FooPtr(std::make_shared<int>(1));
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}

void Foo(int* ptr)
{
	*ptr = *ptr + 1;
}

void FooPtr(std::shared_ptr<int> smartPtr)
{
	std::cout << *smartPtr << std::endl;
}