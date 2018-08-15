#pragma once

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
	Circle();
	Circle(const Point& p);
	virtual ~Circle();

public:
	void Draw() override;
	void Move(const Point& center) override;

private:
	Point center_;
};