#include "pch.h"

template<typename T, std::size_t N>
constexpr std::size_t ArraySize(T(&)[N]) noexcept
{
	return N;
}

int main(int argc, char* argv[])
{
	int keyVals[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << ArraySize(keyVals) << std::endl;

	return EXIT_SUCCESS;
}