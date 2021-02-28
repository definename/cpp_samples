#include <iostream>
#include <cassert>
#include <limits>

int main(int argc, char* argv[])
{
	//////////////////////////////////////////////////////////////////////////
	// These two expression are same
	//////////////////////////////////////////////////////////////////////////

	unsigned int ui_max = std::numeric_limits<unsigned int>::max();
	unsigned int ui_min = std::numeric_limits<unsigned int>::min();
	long l_max = std::numeric_limits<long>::max();

	std::cout << "unsigned int min:" << ui_min << std::endl;
	std::cout << "unsigned int max:" << ui_max << std::endl;
	std::cout << "long max:" << l_max << std::endl;

	std::cout << ui_max - 25u << std::endl;

	std::cout << "................" << std::endl;
	unsigned int ui = 25u;
	std::cout << ui - 50 << std::endl;
	std::cout << (int)ui - 50 << std::endl;

	std::cout << "................" << std::endl;
	std::cout << 50 - ui << std::endl;
	std::cout << 50 - (int)ui << std::endl;

	{
		std::cout << "................" << std::endl;
		auto a = 50 - ui_max;
		auto b = ui_min + 50 + 1;
		assert(a == b);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	{
		std::cout << "................" << std::endl;
		int x = -1;
		unsigned int y = 200U;
		std::cout << (unsigned int)x << "\n";
		// TYPE OF X(INT) CONVERTS TO TYPE OF Y(UNSIGNED INT)
		//
		// + if one operand has an unsigned type T whose conversion rank is at least as high as that of the other operand’s type,
		// then the other operand is converted to type T
		if (x < y)  {
			std::cout << "WILL NEVER BE CALLED" << std::endl;
		}
	}

	{
		std::cout << "................" << std::endl;
		long x = 3L;
		unsigned int y = std::numeric_limits<unsigned int>::max();
		// TYPE OF Y(UNSIGNED INT) CONVERTS TO TYPE OF X(LONG)
		//
		// + if the value range of long contains the whole value range of unsigned int
		// - if not—for example, if both int and long are 32 bits wide—then both multiplicands are converted to unsigned long
		std::cout << x + y << std::endl;
	}

	{
		unsigned char limit = 150;

		// unsigned char i will never be more than 255 - INFINITE LOOP OBSERVED!!!

		// for(unsigned char i = 0; i < 2 * limit; ++i) {
		// 	std::cout << (int)i << " ";
		// }
	}

	{
		std::cout << "................" << std::endl;
		unsigned char i = 300;
		// unsigned char i will have value 44
		assert(i == 44);
		// value of unsigned char i less than 200
		if (i > 200) {
			std::cout << "WILL NEVER BE CALLED" << std::endl;
		}
	}

	{
		std::cout << "................" << std::endl;
		char arr[] = "0123456789abcd";
		uint32_t c = 0x55555555;
		*((uint32_t*)arr + 1) = c;
		std::cout << arr << std::endl;
	}
	return 0;
}