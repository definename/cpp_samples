class Min : public std::unary_function<int, void>
{
public:
	Min()
		: min(-1)
		, first(true)
	{};

	void operator() (std::pair<int, int> el)
	{
		if (first)
		{
			first = false;
			min = el.second;
		}
		else if (min > el.second)
		{
			min = el.second;
		}
	};

public:
	bool first;
	int min;
};