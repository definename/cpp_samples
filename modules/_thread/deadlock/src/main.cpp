#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>

std::mutex mutex_a;
std::mutex mutex_b;

std::atomic<bool> ready_a(false);
std::atomic<bool> ready_b(false);

void resource_A(void) {
	std::lock_guard<std::mutex> l(mutex_a);
	std::cout << "A locked..." << std::this_thread::get_id() << std::endl;
}

void resource_B(void) {
	std::lock_guard<std::mutex> l(mutex_b);
	std::cout << "B locked..." << std::this_thread::get_id() << std::endl;
}

void handle_A(void) {
	std::lock_guard<std::mutex> l(mutex_a);
	ready_a = true;
	std::cout << "handle A locked...\n";
	while (!ready_a && !ready_b) {
	}
	// TODO: Deadlock here
	resource_B();
}

void handle_B(void) {
	std::lock_guard<std::mutex> l(mutex_b);
	ready_b = true;
	std::cout << "handle B locked...\n";
	while (!ready_a && !ready_b) {
	}
	// TODO: Deadlock here
	resource_A();
}

int main(int argc, char* argv[]) {
	int count = 100;
	while (count) {
		std::thread t1(handle_A);
		std::thread t2(handle_B);
		t1.join();
		t2.join();
		--count;
	}
	return EXIT_SUCCESS;
}