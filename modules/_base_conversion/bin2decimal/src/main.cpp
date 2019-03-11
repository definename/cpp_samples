#include "pch.h"

int main(int argc, char* argv[])
{
	int num = 110011;
	// 1*1 + 1*2 + 0*4 + 0*8 + 1*16 + 1*32 ...
	std::cout << "binary number: " << num << std::endl;

	int decimal = 0;
	int degree = 1;
	while (num != 0)
	{
		int remainder = num % 10;
		num /= 10;
		std::cout << remainder << "*" << degree << std::endl;
		remainder *= degree;
		degree *= 2;
		decimal += remainder;
	}

	std::cout << "decimal number: " << decimal << std::endl;
	return 0;
}