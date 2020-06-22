#include <iostream>
#include <cstring>
#include <algorithm>

static int* init_array(const int size) {
	int *arr = new int[size];
	for (int i = 0; i < size; ++i) {
		int num = std::rand() % 30;
		arr[i] = num;
	}

	std::sort(arr, arr + size);
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return arr;
}

static int binary_search(int low, int high, const int key, const int* const arr) {
	if (low <= high) {
		int mid = (low + high) / 2;
		if (key == arr[mid]) {
			return mid;
		} else if(key > arr[mid]) {
			return binary_search(mid + 1, high, key, arr);
		} else {
			return binary_search(low, mid - 1, key, arr);
		}
	}
	return -1;
}

int main(int argc, char* argv[]) {
	std::srand(1);

	const int size = 15;
	int* arr = init_array(size);

	const int key = 20;
	int found = binary_search(0, size -1, key, arr);
	if (found == -1) {
		std::cout << "not found" << std::endl;
	} else {
		std::cout << "found at:" << found << std::endl;
	}

	return EXIT_SUCCESS;
}