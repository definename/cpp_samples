#pragma once

#include "Shape.h"
#include "Point.h"

class Square : public Shape
{
public:
	Square();
	Square(const Point& p);
	virtual ~Square();

public:
	void Draw() override;
	void Move(const Point& p) override;

private:
	Point topLeft_;
};