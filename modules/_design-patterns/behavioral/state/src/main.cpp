#include "pch.h"

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		_tcout << _T("Is not implemented") << std::endl;
	}
	catch (const std::exception& e)
	{
		_tcerr << _T("Error occurred: ") << e.what() << std::endl;
	}
}