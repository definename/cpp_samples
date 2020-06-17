#include <iostream>
#include <ctime>
#include <cstring>

// Sorting algorithms
static void bubble_sort(int* const arr, const int size);

// Support function
static void dump_array(int* const arr, const int size, const char * const title) {
	std::cout << title << " sorted:" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	// Init origin array
	const int size = 15;
	int *arr = new int[size];
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::cout << "Origin array:" << std::endl;
	for (int i = 0; i < size; ++i) {
		int num = std::rand() % 30;
		arr[i] = num;
		std::cout << num << " ";
	}
	std::cout << std::endl;

	// Bubble sort
	int* bubble_sorted = new int[size];
	std::memcpy(bubble_sorted, arr, size * sizeof(int));
	bubble_sort(bubble_sorted, size);
	dump_array(bubble_sorted, size, "Bubble");

	delete [] bubble_sorted;
	bubble_sorted = nullptr;

	// Another sorting algorithms
	delete [] arr;
	arr = nullptr;

	return EXIT_SUCCESS;
}

static void bubble_sort(int *const arr, const int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}