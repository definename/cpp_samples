#include "pch.h"

std::string ChangeBase(int decimal, const unsigned int base);

int main(int argc, char* argv[])
{
	std::cout << "Enter decimal number: ";
	unsigned int decimal;
	std::cin >> decimal;

	std::cout << "Decimal: " << ChangeBase(decimal, 2) << std::endl;
	std::cout << "Octal: " << ChangeBase(decimal, 8) << std::endl;
	std::cout << "Hex: " << ChangeBase(decimal, 16) << std::endl;

	return 0;
}

std::string ChangeBase(int decimal, const unsigned int base)
{
	std::string res;
	while (decimal != 0)
	{
		int remainder(decimal % base);
		if (remainder == 10) {
			res.push_back('A');
		}
		else if (remainder == 11) {
			res.push_back('B');
		}
		else if (remainder == 12) {
			res.push_back('C');
		}
		else if (remainder == 13) {
			res.push_back('D');
		}
		else if (remainder == 14) {
			res.push_back('E');
		}
		else if (remainder == 15) {
			res.push_back('F');
		}
		else {
			res.push_back((decimal % base) + '0');
		}
		decimal /= base;
	}
	std::reverse(res.begin(), res.end());
	return res;
}