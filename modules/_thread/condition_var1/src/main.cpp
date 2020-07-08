#include <iostream>
#include <thread>
#include <condition_variable>

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
	return EXIT_SUCCESS;
}