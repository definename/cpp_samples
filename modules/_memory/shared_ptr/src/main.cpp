#include "pch.h"

struct Test {
	int val1_;
	int val2_;
};

struct Person
{
	Person(const std::string& name)
		: name_(name)
	{
	}
	~Person()
	{
		std::cout << "Person destroyed: " << name_ << std::endl;
	}

	//! It works.
	// std::weak_ptr<Person> part_;
	//! It does not work.
	std::shared_ptr<Person> part_;
	std::string name_;
};

int main(int argc, TCHAR* argv[])
{
	try
	{
		auto del = [](Test* t) {
			std::cout << "Test val1 is being destroyed: " << t->val1_ << std::endl;
			std::cout << "Test val2 is being destroyed: " << t->val2_ << std::endl;
			delete t;
		};

		std::shared_ptr<Test> obj1(new Test{ 99, 11 }, del);

		// Person destructor is never called, use weak_ptr for Person member.
		{
			std::shared_ptr<Person> p2(new Person("Person2"));
			std::shared_ptr<Person> p1(new Person("Person1"));

			p1->part_ = p2;
			p2->part_ = p1;

			std::cout << p1.use_count() << std::endl;
			std::cout << p2.use_count() << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		_tcerr << _T("Error occurred: ") << e.what() << std::endl;
	}

	return 0;
}