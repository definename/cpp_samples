#include "pch.h"
#include "Square.h"

Square::Square()
	: topLeft_(Point(0,0))
{}

Square::Square(const Point& topLeft)
	: topLeft_(topLeft)
{ }

Square::~Square()
{
	_tcout << _T("Square has been destroyed") << std::endl;
}

void Square::Draw()
{
	_tcout << _T("Square has been drown") << std::endl;
}

void Square::Move(const Point& topLeft)
{
	topLeft_ = topLeft;
	_tcout << _T("Square has been moved to: ") << topLeft_.x_ << _T(":") << topLeft_.y_ << std::endl;
}