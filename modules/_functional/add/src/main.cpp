#include "pch.h"

class Box
{
	// Construction and destruction.
public:
	//! Constructor.
	Box()
		: count_(0)
	{ }
	//! Constructor.
	explicit Box(const int count)
		: count_(count)
	{ }

public:
	//! Allows access to private data members.
	friend Box operator+(const Box& obj1, const Box& obj2);
	// Operator plus.
	Box& operator+(const Box& obj)
	{
		count_ += obj.count_;
		return *this;
	}

	//! Gets count.
	int GetCount() const
	{
		return count_;
	}

private:
	//! Count.
	int count_;
};

// Operator plus.
Box operator+(const Box& obj1, const Box& obj2)
{
	Box res(obj1.count_);
	res.count_ += obj2.count_;

	return res;
}

//Functor1 (Functional object)
template <typename T>
struct Add1
{
	T operator()(T& x, const T& y) const
	{
		return x + y;
	}
};

//Functor2 (Functional object)
struct Add2
{
	template <typename T>
	T operator()(const T& x, const T& y) const
	{
		return x + y;
	}
};

// Storage type.
using Storage = std::forward_list<Box>;

void _tmain(int argc, TCHAR* argv[])
{
	Storage boxes;
	for (auto i = 0; i != 10; ++i)
		boxes.emplace_front(1);

	_tcout << _T("Functor1: ") << std::accumulate(
		boxes.cbegin(),
		boxes.cend(),
		Box(0),
		Add1<Storage::value_type>()).GetCount() << std::endl;

	_tcout << _T("Functor2: ") << std::accumulate(
		boxes.cbegin(),
		boxes.cend(),
		Box(0),
		Add2()).GetCount() << std::endl;
}