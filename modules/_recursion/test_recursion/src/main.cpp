#include <iostream>

void func(const int i) {
	if (i > 0) {
		std::cout << i << " ";
		func(i - 1);
		std::cout << i << " ";
	}
}

int main(int argc, char* argv[]) {
	func(10);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}