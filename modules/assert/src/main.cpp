#include "pch.h"

template<class Error, class A> inline void MyAssert(A assertin)
{
	if (!assertin)
		throw Error("Assert occured");
}

class MyExeption : public std::exception
{
public:
	MyExeption(const char * const & e)
		: std::exception(e)
	{ }
	~MyExeption() { };
};

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		int one = 1;
		int two = 2;
		//! STL assert implementation.
		assert(one == two);
		//! My Assert implementation.
		//MyAssert<MyExeption>(one == two);
	}
	catch (const std::exception& e)
	{
		_tcerr << _T("Error occurred: ") << e.what() << std::endl;
	}
}