#include "pch.h"

int myatoi(const char* ch);
void myitoa(char* ch, int num, int base = 10);

int main(int argc, char* argv[])
{
	try
	{
		{
			char* ch = "120";
			std::cout << myatoi(ch) + 1 << std::endl;
		}

		{
			char* ch = new char[100];
			myitoa(ch, 120);
			std::cout << ch << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error occurred: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

int myatoi(const char* ch)
{
	int res = 0;
	for (int i = 0; ch[i] != '\0'; ++i)
	{
		res = res * 10 + ch[i] - 0x30;
	}
	return res;
}

void myitoa(char* ch, int num, int base/* = 10*/)
{
	int i = 0;
	while (num != 0)
	{
		int rem = num % base;
		ch[i++] = rem + 0x30;
		num /= base;
	}
	ch[i] = '\0';

	int start = 0;
	int end = i - 1;
	while (start < end)
	{
		char temp = ch[start];
		ch[start] = ch[end];
		ch[end] = temp;

		start++;
		end--;
	}
}