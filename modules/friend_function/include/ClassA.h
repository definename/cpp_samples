#pragma once

class ClassB;
class ClassA
{
	friend int operator*(const ClassA&, const ClassB&);
	friend int operator*(const ClassB&, const ClassA&);
public:
	ClassA();
	~ClassA();

private:
	int a_;
};