#include "pch.h"

void done();
void done1();

int _tmain(int argc, TCHAR* argv[])
{
	if (atexit(&done) == 0) {
		_tcout << "Termination handler #0 has been set" << std::endl;
	}
	else {
		_tcerr << "Unable to set termination handler" << std::endl;
	}

	if (atexit(&done1) == 0) {
		_tcout << "Termination handler #1 has been set" << std::endl;
	}
	else {
		_tcerr << "Unable to set termination handler" << std::endl;
	}

	return 0;
}

void done()
{
	::MessageBox(NULL, _T("Program terminets noramlly"), _T("Termination handler #0"), MB_ICONINFORMATION);
}

void done1()
{
	::MessageBox(NULL, _T("Program terminets noramlly"), _T("Termination handler #1"), MB_ICONINFORMATION);
}