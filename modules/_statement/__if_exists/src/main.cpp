#include "pch.h"
#include "Version.h"

bool flag = true;

int _tmain(int argc, TCHAR* argv[], TCHAR* env[])
{
	__if_exists(::flag)
	{
		if (flag)
			std::cout << VERSION << std::endl;
	}

	return 0;
}