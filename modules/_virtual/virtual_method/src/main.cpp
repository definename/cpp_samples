#include <iostream>

class A {
	public:
	A() {
		run();
	}
	~A() {
		run();
	}
	virtual void run() const {
		std::cout << "A" << std::endl;
	}
};

class B: public A {
	public:
	B() = default;
	~B() = default;

	void run() const override {
		std::cout << "WILL NEVER BE CALLED" << std::endl;
	}
};

int main(int argc, char* argv[]) {
	B d;
	B *dd = new B();
	delete dd;
	return EXIT_SUCCESS;
}