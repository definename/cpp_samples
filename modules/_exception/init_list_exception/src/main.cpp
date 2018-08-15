#include "pch.h"

class bb8
{
public:
	bb8() {
		throw(std::runtime_error("Unable to initialize bb8"));
	}
	~bb8() {
		_tcout << _T("bb8 has been destroyed") << std::endl;
	}

public:
	const int val_ = 10;
};

class r2d2
{
public:
	r2d2()
		try
		: val_(bb8().val_)
	{

	}
	catch (const std::exception& e) {
		_tcout << _T("r2d2 has broken: ") << e.what() << std::endl;
	}
	~r2d2() {
		_tcout << _T("r2d2 has been destroyed") << std::endl;
	}

private:
	const int val_;
};

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		r2d2 robot;
	}
	catch (const std::exception& e)
	{
		_tcerr << _T("Error occurred: ") << e.what() << std::endl;
	}
}