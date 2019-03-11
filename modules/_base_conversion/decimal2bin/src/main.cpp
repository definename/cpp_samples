#include "pch.h"

int main(int argc, char* argv[])
{
	std::cout << "Enter decimal number: ";
	unsigned int num;
	std::cin >> num;

	unsigned int arr[16];
	for (unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		arr[i] = 0;
	}

	unsigned int count = sizeof(arr) / sizeof(arr[0]) - 1;
	while (num != 0)
	{
		arr[count--] = num % 2;
		num /= 2;
	}

	for (unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		if (i % 4 == 0 && i != 0) {
			std::cout << " ";
		}
		std::cout << arr[i];
	}
	std::cout << std::endl;

	return 0;
}