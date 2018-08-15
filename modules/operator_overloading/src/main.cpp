#include "pch.h"
#include "Overload.h"

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		//! Index.
		Overload over;
		_tcout << over[0] << std::endl;
		const Overload constOver;
		_tcout << constOver[1] << std::endl;

		//! Typecasting.
		_tstring overStr = constOver;
		_tcout << overStr << std::endl;

		//! Plus.
		Overload plus1(_T("string1"));
		Overload plus2(_T("string2"));
		_tcout << (plus1 + plus2).GetStr() << std::endl;

		//! Minus.
		Overload minus1(_T("string1"), 10);
		Overload minus2(_T("string2"), 20);
		_tcout << (minus1 - minus2).GetNum() << std::endl;

		//! Multiply.
		Overload multiply1(_T("string1"), 20);
		Overload multiply2(_T("string2"), 10);
		_tcout << (multiply1 * multiply2).GetNum() << std::endl;

		//! Divide.
		Overload devide1(_T("string1"), 10);
		Overload devide2(_T("string2"), 20);
		_tcout << (devide1 / devide2).GetNum() << std::endl;

		//! Pre-increment.
		Overload preIncrement(_T("string1"), 10);
		_tcout << (++preIncrement).GetNum() << std::endl;

		//! Pre-decrement.
		Overload preDecrement(_T("string1"), 10);
		_tcout << (--preDecrement).GetNum() << std::endl;

		//! Post-increment.
		Overload postIncrement(_T("string1"), 10);
		_tcout << (postIncrement++).GetNum() << std::endl;
		_tcout << postIncrement.GetNum() << std::endl;

		//! Post-decrement.
		Overload postDecrement(_T("string1"), 10);
		_tcout << (postDecrement--).GetNum() << std::endl;
		_tcout << postDecrement.GetNum() << std::endl;

		Overload inout;
		_tcout << inout;
		_tcin >> inout;
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}