#include "pch.h"
#include "Test.h"

void Sink(std::unique_ptr<int> ptr);
std::unique_ptr<int> Source();

void main(int argc, char* argv[])
{
	try
	{
		{
			std::unique_ptr<int> ptr(new int(10));
			std::unique_ptr<int> ptr1(std::move(ptr));
			std::unique_ptr<int> ptr2;
			ptr2 = std::move(ptr1);

			if (ptr)
				std::cout << "Origin: " << *ptr << std::endl;
			if (ptr1)
				std::cout << "Copy1: " << *ptr1 << std::endl;
			if (ptr2)
				Sink(std::move(ptr2));

			ptr2 = Source();
			if (ptr2)
				Sink(std::move(ptr2));
		}

		{
			ClassB b1(1, 2);
			ClassB b2(b1);

			std::cout << b1.ptr1_->val_ << std::endl;
			std::cout << b1.ptr2_->val_ << std::endl;

			std::cout << b2.ptr1_->val_ << std::endl;

			std::cout << b2.ptr2_->val_ << std::endl;
		}

		{
			auto del = [](ClassA* a) {
				std::cout << "Class A has been destroyed: " << a->val_ << std::endl;
				delete a;
			};
			std::unique_ptr<ClassA, decltype(del)> obj1(new ClassA(999), del);
			std::unique_ptr<ClassA, void(*)(ClassA*)> obj2(new ClassA(999), del);
		}

		{
			std::unique_ptr<int[]> array(new int[10]);
			for (int i = 0; i != 10; ++i) {
				array[i] = i;
			}
			std::cout << array[9] << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
}

void Sink(std::unique_ptr<int> ptr)
{
	if (ptr) std::cout << "Sink: " << *ptr << std::endl;
}

std::unique_ptr<int> Source()
{
	return std::make_unique<int>(99);
}