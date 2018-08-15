#include "pch.h"

void error(int severity ...);

void _tmain(int argc, TCHAR* argv[])
{
	error(100, NULL);
	error(200, _T("Unknown error"), NULL);
	error(300, _T("Unknown error"), _T("Network error"), NULL);
}

void error(int severity ...)
{
	va_list ap;
	va_start (ap, severity);
	while(true)
	{
		TCHAR* p = va_arg(ap, TCHAR*);
		if (p == 0)
			break;

		_tcout << severity << _T(" ") << p << std::endl;
	}
	va_end(ap);
}
