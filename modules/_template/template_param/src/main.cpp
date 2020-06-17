#include <iostream>

template<typename T, int size>
class MyArray {
	public:
	const static int my_size = size;

	MyArray() {
		for (int i = 0; i < my_size; ++i) {
			data_[i] = i + 1;
		}
	}

	void Print() const {
		for (int i = 0; i < my_size; ++i) {
			std::cout << data_[i] << " ";
		}
		std::cout << std::endl;
	}

	private:
	T data_[my_size];
};

int main(int argc, char* argv[]) {
	MyArray<int, 10> arr;
	arr.Print();

	return EXIT_SUCCESS;
}