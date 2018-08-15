#pragma once

class ClassA;
class ClassB
{
	friend int operator*(const ClassA&, const ClassB&);
	friend int operator*(const ClassB&, const ClassA&);
public:
	ClassB();
	~ClassB();

private:
	int b_;
};