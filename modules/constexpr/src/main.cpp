#include "pch.h"

template <typename T>
void PRINT_COLLECTION(T coll) {
	for (const auto& val : coll) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

constexpr int size(int size) noexcept {
	return size * 2;
}

int main(int argc, char* argv[])
{
	try {

// 		int sz;
// 		const auto size1 = sz; // OK!
// 		constexpr auto size2 = sz; // Error

		constexpr auto s = 5;
		std::array<int, size(s)> arr = { 5, 4, 3, 2, 1, 1, 2, 3, 4, 5 };
		PRINT_COLLECTION(arr);
	}
	catch (const std::exception& e) {
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}