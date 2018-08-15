#include "pch.h"

// std::string ROT13(std::string original)
// {
// 	std::string result = original;
// 	for (unsigned int a = 0; a<result.length(); ++a)
// 	{
// 		switch (result[a])
// 		{
// 		case 'a':
// 			result[a] = 'n';
// 			break;
// 		case 'A':
// 			result[a] = 'N';
// 			break;
// 		case 'b':
// 			result[a] = 'o';
// 			break;
// 		case 'B':
// 			result[a] = 'O';
// 			break;
// 		case 'c':
// 			result[a] = 'p';
// 			break;
// 		case 'C':
// 			result[a] = 'P';
// 			break;
// 		case 'd':
// 			result[a] = 'q';
// 			break;
// 		case 'D':
// 			result[a] = 'Q';
// 			break;
// 		case 'e':
// 			result[a] = 'r';
// 			break;
// 		case 'E':
// 			result[a] = 'R';
// 			break;
// 		case 'f':
// 			result[a] = 's';
// 			break;
// 		case 'F':
// 			result[a] = 'S';
// 			break;
// 		case 'g':
// 			result[a] = 't';
// 			break;
// 		case 'G':
// 			result[a] = 'T';
// 			break;
// 		case 'h':
// 			result[a] = 'u';
// 			break;
// 		case 'H':
// 			result[a] = 'U';
// 			break;
// 		case 'i':
// 			result[a] = 'v';
// 			break;
// 		case 'I':
// 			result[a] = 'V';
// 			break;
// 		case 'j':
// 			result[a] = 'w';
// 			break;
// 		case 'J':
// 			result[a] = 'W';
// 			break;
// 		case 'k':
// 			result[a] = 'x';
// 			break;
// 		case 'K':
// 			result[a] = 'X';
// 			break;
// 		case 'l':
// 			result[a] = 'y';
// 			break;
// 		case 'L':
// 			result[a] = 'Y';
// 			break;
// 		case 'm':
// 			result[a] = 'z';
// 			break;
// 		case 'M':
// 			result[a] = 'Z';
// 			break;
// 		case 'n':
// 			result[a] = 'a';
// 			break;
// 		case 'N':
// 			result[a] = 'A';
// 			break;
// 		case 'o':
// 			result[a] = 'b';
// 			break;
// 		case 'O':
// 			result[a] = 'B';
// 			break;
// 		case 'p':
// 			result[a] = 'c';
// 			break;
// 		case 'P':
// 			result[a] = 'C';
// 			break;
// 		case 'q':
// 			result[a] = 'd';
// 			break;
// 		case 'Q':
// 			result[a] = 'D';
// 			break;
// 		case 'r':
// 			result[a] = 'e';
// 			break;
// 		case 'R':
// 			result[a] = 'E';
// 			break;
// 		case 's':
// 			result[a] = 'f';
// 			break;
// 		case 'S':
// 			result[a] = 'F';
// 			break;
// 		case 't':
// 			result[a] = 'g';
// 			break;
// 		case 'T':
// 			result[a] = 'G';
// 			break;
// 		case 'u':
// 			result[a] = 'h';
// 			break;
// 		case 'U':
// 			result[a] = 'H';
// 			break;
// 		case 'v':
// 			result[a] = 'i';
// 			break;
// 		case 'V':
// 			result[a] = 'I';
// 			break;
// 		case 'w':
// 			result[a] = 'j';
// 			break;
// 		case 'W':
// 			result[a] = 'J';
// 			break;
// 		case 'x':
// 			result[a] = 'k';
// 			break;
// 		case 'X':
// 			result[a] = 'K';
// 			break;
// 		case 'y':
// 			result[a] = 'l';
// 			break;
// 		case 'Y':
// 			result[a] = 'L';
// 			break;
// 		case 'z':
// 			result[a] = 'm';
// 			break;
// 		case 'Z':
// 			result[a] = 'M';
// 			break;
// 		}
// 	}
// 	return result;
// }

std::string ROT13(std::string input)
{
	for (size_t idx = 0; idx != input.length(); ++idx)
	{
		if ((input[idx] >= 'a' && input[idx] <= 'm') ||
			(input[idx] >= 'A' && input[idx] <= 'M'))
		{
			input[idx] = input[idx] + 13;
		}
		else if ((input[idx] >= 'n' && input[idx] <= 'z') ||
			(input[idx] >= 'N' && input[idx] <= 'Z'))
		{
			input[idx] = input[idx] - 13;
		}
	}

	return input;
}

int main()
{
	std::string str("Uryyb Jbeyq");
	std::cout << ROT13(str) << std::endl;

	return 0;
}