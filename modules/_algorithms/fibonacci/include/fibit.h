#pragma once

class fibit
{
	friend class fibrange;
public:
	fibit() = default;
private:
	fibit(size_t i)
		: i_(i)
	{ }

public:
	bool operator!=(const fibit& other) const
	{
		return other.i_ != i_;
	}

	size_t operator*()
	{
		if (i_ == 0)
		{
			return a_;
		}
		return b_;
	}

	fibit& operator++()
	{
		if (i_ == 1)
		{
			++i_;
			return *this;
		}		

		const size_t temp = b_;
		b_ += a_;
		a_ = temp;

		++i_;
		return *this;
	}

private:
	size_t i_{ 0 };
	size_t a_{ 0 };
	size_t b_{ 1 };
};

class fibrange
{
public:
	fibrange(size_t end)
		: end_(end)
	{ }

public:
	fibit begin() const { return fibit{}; };
	fibit end() const { return fibit{end_}; };

private:
	size_t end_;
};