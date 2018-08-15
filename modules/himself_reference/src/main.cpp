#include "pch.h"

class Number
{
public:
	Number();
	~Number();

public:
	int GetVal();
	Number& PlusOne();

private:
	int n_;
};

Number::Number() :n_(1) { }

Number::~Number() { }

int Number::GetVal() { return n_; }

Number& Number::PlusOne() { n_++; return *this; }

void _tmain(int argc, TCHAR* argv[])
{
	Number num;
	num.PlusOne().PlusOne().PlusOne();
	_tcout << num.GetVal() << std::endl;
}