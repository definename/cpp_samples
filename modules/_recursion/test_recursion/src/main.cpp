#include <iostream>
#include <cassert>

int sum_of_natural_number(const int n) {
	if (n > 0) {
		return sum_of_natural_number(n - 1) + n;
	}
	return 0;
}

int sum_of_natural_number_formula(const int n) {
	return (n*(n+1))/2;
}

int factorial(const int n) {
	assert(n >= 0);
	if (n == 0) {
		return 1;
	}
	return factorial(n - 1) * n;
}

int pow(const int m, const int n) {
	assert(n >= 0);
	if (n == 0) {
		return 1;
	}
	return pow(m, n -1) * m;
}

int fibonacci(const int n) {
	assert(n >= 0);
	if (n <= 1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

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

	// Sum of natural number
	int res_recursion = sum_of_natural_number(7);
	std::cout << "Sum of natural number:" << res_recursion << std::endl;
	int res_formula = sum_of_natural_number_formula(7);
	assert(res_recursion == res_formula);

	// Factorial
	assert(factorial(0) == 1);
	assert(factorial(1) == 1);
	std::cout << "Factorial:" << factorial(3) << std::endl;

	// Power
	assert(pow(100, 0) == 1);
	std::cout << "Power:" << pow(3, 3) << std::endl;

	// Fibonacci
	assert(fibonacci(0) == 0);
	assert(fibonacci(1) == 1);
	std::cout << "Fibonacci:" << fibonacci(10) << std::endl;

	return EXIT_SUCCESS;
}