#pragma once

class Point;
class Shape
{
public:
	virtual ~Shape() { };

public:
	virtual void Draw() = 0;
	virtual void Move(const Point& p) = 0;
};