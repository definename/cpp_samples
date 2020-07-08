#include <iostream>
#include <thread>
#include <condition_variable>

class A {
	public:
	char i;
	virtual ~A() {}
};

class B: public A {
	public:
	char i;
};

class C: public B {
	public:
	char i;
};

class F {
	public:
	char i;
};

class E: public F {
	public:
	char i;
};

class D: public C, public E {
	public:
	char i;
};

std::mutex _m;
std::condition_variable_any _cv;
bool _ready = false;

void handle_wait(void) {
	std::unique_lock<std::mutex> l(_m);
	_cv.wait(l, [](){
		std::cout << std::boolalpha << "ready:" << _ready << "\n";
		return _ready;
		});
	std::cout << "exit" << std::endl;
}

void handle_trigger() {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::unique_lock<std::mutex> l(_m);
	std::cout << "about to trigger\n";
	_ready = true;
	_cv.notify_all();
}

int main(int argc, char* argv[]) {
	std::thread t1(handle_wait);
	std::thread t2(handle_trigger);
	t1.join();
	t2.join();

	A *a1 = new C;
	A *a2 = new D;

	B* b1 = dynamic_cast<B*>(a1);
	{
		B* b1 = static_cast<B*>(a1);
	}

	return EXIT_SUCCESS;
}