#include <iostream>
#include <memory>
#include <string>

class Test1 {
	public:
	Test1() {
		std::cout << "Test1 constructed" << std::endl;
	}
};

class Test2 {
	public:
	Test2() {
		std::cout << "Test2 constructed" << std::endl;
	}
};

class Test {
	public:
	Test()
	: will_be_initialized_second_(Test1())
	, will_be_initialized_first_(Test2()) {
	}
	Test2 will_be_initialized_first_;
	Test1 will_be_initialized_second_;
};

struct Person
{
	Person(const std::string& name)
		: name_(name) {
	}
	~Person() {
		std::cout << "Person destroyed: " << name_ << std::endl;
	}

	//! It works.
	std::weak_ptr<Person> part_;
	//! It does not work.
	// std::shared_ptr<Person> part_;
	std::string name_;
};

int main(int argc, char* argv[])
{
	try {
		auto del = [](Test* t) {
			std::cout << "Test object is being destroyed:" << t << std::endl;
			delete t;
		};
		std::shared_ptr<Test> obj1(new Test, del);

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
	catch (const std::exception& e) {
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}