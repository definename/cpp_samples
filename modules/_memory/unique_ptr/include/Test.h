#pragma once

class ClassA
{
public:
	ClassA()
		: val_(0)
	{ }

	ClassA(const int val)
		: val_(val)
	{ }

	ClassA(const ClassA& x)
		: val_(x.val_)
	{ }

	const ClassA& operator= (const ClassA& x)
	{
		val_ = x.val_;
		return *this;
	}

public:
	int val_;
};

class ClassB
{
public:
	ClassB()
		: ptr1_(nullptr)
		, ptr2_(nullptr)
	{ }

	ClassB(const int val1, const int val2)
		: ptr1_(new ClassA(val1))
		, ptr2_(new ClassA(val2))
	{ }

	ClassB(const ClassB& x)
		: ptr1_(new ClassA(*x.ptr1_))
		, ptr2_(new ClassA(*x.ptr2_))
	{ }

	const ClassB& operator= (const ClassB& x)
	{
		*ptr1_ = *x.ptr1_;
		*ptr2_ = *x.ptr2_;
		return *this;
	}

public:
	std::unique_ptr<ClassA> ptr1_;
	std::unique_ptr<ClassA> ptr2_;
};