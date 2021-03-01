#include <iostream>

class A {
	public:
	A() {
		run();
	}
	virtual ~A() {
		run();
	}
	virtual void run() = 0;
};

void A::run() {
	std::cout << "A" << std::endl;
}

class B: public A {
	public:
	B() = default;
	~B() {
		std::cout << "B destroyed" << std::endl;
	};

	void run() override {
		A::run();
		std::cout << "WILL NEVER BE CALLED" << std::endl;
	}
};

int main(int argc, char* argv[]) {
	B bb;
	A *aa = new B();
	delete aa;
	return EXIT_SUCCESS;
}