#include "pch.h"

int _tmain(int argc, TCHAR* argv [])
{
	TCHAR arr1[100] = _T("C ++ program");
	//! Marco - determines buffer size.
	std::cout << _countof(arr1) << std::endl;
	std::cout << sizeof(arr1) << std::endl;

	TCHAR arr2[] = _T("123");
	std::cout << _countof(arr2) << std::endl;
	std::cout << sizeof(arr2) << std::endl;

	const TCHAR* arr3 = _T("123");
	std::cout << _tcslen(arr3) << std::endl;


	return 0;
}