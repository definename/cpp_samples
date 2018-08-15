#pragma once

class Overload
{
public:
	Overload();
	Overload(const _tstring& str);
	Overload(const _tstring& str, const int& valNum);
	~Overload();

public:
	const int& GetNum() const;
	const _tstring& GetStr() const;

public:
	TCHAR& operator[] (const int& pos);
	const TCHAR& operator[] (const int& pos) const;

	operator _tstring() const;

	//! Binary operation.
	Overload& operator-(const Overload& obj);
	Overload& operator+(const Overload& obj);
	Overload& operator*(const Overload& obj);
	Overload& operator/(const Overload& obj);

	//! Unary operation.
	//! Prefix.
	Overload& operator++();
	Overload& operator--();
	//! Postfix.
	Overload operator++(int);
	Overload operator--(int);

	friend _tostream& operator<<(_tostream& out, const Overload& obj);
	friend _tistream& operator>>(_tistream& ist, Overload& obj);


private:
	_tstring valStr_;
	int valNum_;
};