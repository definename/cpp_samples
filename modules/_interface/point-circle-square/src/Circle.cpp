#include "pch.h"
#include "Circle.h"
#include "Point.h"

Circle::Circle()
	: center_(Point(0,0))
{ }

Circle::Circle(const Point& p)
	: center_(p)
{ }

Circle::~Circle()
{
	_tcout << _T("Circle has been destroyed") << std::endl;
}

void Circle::Draw()
{
	_tcout << _T("Circle has been drown") << std::endl;
}

void Circle::Move(const Point& center)
{
	center_ = center;
	_tcout << _T("Circle has been moved to: ") << center_.x_ << _T(":") << center_.y_ << std::endl;
}