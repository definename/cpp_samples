#pragma once

class Point
{
public:
	Point();
	Point::Point(const int& x, const int y);
	~Point();

public:
	int x_;
	int y_;
};