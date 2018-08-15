#include "pch.h"
#include "Overload.h"

_tostream& operator<<(_tostream& out, const Overload& obj)
{
	_tcout << _T("::ostream") << std::endl;
	out << obj.valNum_ << std::endl;
	return out;
}

_tistream& operator>>(_tistream& ist, Overload& obj)
{
	_tcout << _T("::istream") << std::endl;
	ist >> obj.valNum_;
	return ist;
}

Overload::Overload()
	: valStr_(_T("string"))
	, valNum_(1000)
{ }

Overload::Overload(const _tstring& str)
	: valStr_(str)
	, valNum_(1000)
{ }

Overload::Overload(const _tstring& str, const int& valNum)
	: valStr_(str)
	, valNum_(valNum)
{ }

Overload::~Overload()
{ }

const int& Overload::GetNum() const
{
	return valNum_;
}

const _tstring& Overload::GetStr() const
{
	return valStr_;
}

TCHAR& Overload::operator[](const int& pos)
{
	_tcout << _T("::index non constant method") << std::endl;
	return valStr_.at(pos);
}

const TCHAR& Overload::operator[] (const int& pos) const
{
	_tcout << _T("::index constant method") << std::endl;
	return valStr_.at(pos);
}

Overload::operator _tstring() const
{
	_tcout << _T("::type casting") << std::endl;
	return valStr_;
}

Overload& Overload::operator+(const Overload& obj)
{
	_tcout << _T("::plus") << std::endl;
	valStr_ = valStr_ + obj.valStr_;
	return *this;
}

Overload& Overload::operator-(const Overload& obj)
{
	_tcout << _T("::minus") << std::endl;
	valNum_ = valNum_ - obj.valNum_;
	return *this;
}

Overload& Overload::operator*(const Overload& obj)
{
	_tcout << _T("::multiply") << std::endl;
	valNum_ = obj.valNum_ * valNum_;
	return *this;
}

Overload& Overload::operator/(const Overload& obj)
{
	_tcout << _T("::divide") << std::endl;
	valNum_ = obj.valNum_ / valNum_;
	return *this;
}

Overload& Overload::operator++()
{
	_tcout << _T("::pre-increment") << std::endl;
	valNum_++;
	return *this;
}

Overload& Overload::operator--()
{
	_tcout << _T("::pre-decrement") << std::endl;
	valNum_--;
	return *this;
}

Overload Overload::operator++(int)
{
	_tcout << _T("::post-increment") << std::endl;
	Overload temp = *this;
	++*this;
	return temp;
}

Overload Overload::operator--(int)
{
	_tcout << _T("::post-decrement") << std::endl;
	Overload temp = *this;
	--*this;
	return temp;
}