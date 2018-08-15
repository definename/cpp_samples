#include "pch.h"
#include "ClassA.h"
#include "ClassB.h"

int operator*(const ClassA& a, const ClassB& b)
{
	return a.a_ * b.b_;
}

int operator*(const ClassB& b, const ClassA& a)
{
	return b.b_ * a.a_;
}