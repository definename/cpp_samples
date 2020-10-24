#include <iostream>
#include <string>
#include <mutex>
#include <stack>
#include <future>
#include <memory>
#include <thread>
#include <vector>

std::mutex mutex_;
std::condition_variable cv_;
bool done_ = false;

void Waiter();
void Cook();

int main(int argc, char* argv[]) {
	try {
		std::vector<std::thread> v;
		v.push_back(std::thread(Waiter));
		v.push_back(std::thread(Cook));

		for (auto& t: v) {
			t.join();
		}

		// auto t1 = std::async(std::launch::async, Waiter);
		// auto t2 = std::async(std::launch::async, Cook);
	}
	catch (const std::exception& e) {
		std::cerr << "Error occurred: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void Waiter() {
	while (true) {
		std::unique_lock<std::mutex> l(mutex_);
		cv_.wait(l, []() { return done_; });

		{
			l.unlock();
			std::this_thread::sleep_for(std::chrono::seconds(6));
			l.lock();

			std::cout << "Has been eaten!!" << std::endl;
			done_ = false;
		}
	}
}

void Cook() {
	while (true) {
		{
			std::unique_lock<std::mutex> l(mutex_);
			if (!cv_.wait_for(l, std::chrono::seconds(1), []() { return !done_; })) {
				std::cout << "Is not eaten!!" << std::endl;
				continue;
			}

			done_ = true;
			std::cout << "Cooked!!" << std::endl;
		}
		cv_.notify_one();
	}
}