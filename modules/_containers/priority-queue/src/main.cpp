#include "pch.h"

struct Obj
{
	int val_;
};

void defaultPriority();
void greaterPriority();
void MyQueueComparator();

int main()
{
	defaultPriority();
	std::cout << std::endl;
	greaterPriority();

	MyQueueComparator();

	return 0;
}

void MyQueueComparator()
{
	// Queue with objects.
	std::vector<Obj> vec;
	for (int i = 0; i != 10; ++i)
	{
		Obj obj;
		obj.val_ = i;
		vec.push_back(obj);
	}

	typedef std::priority_queue<Obj, std::vector<Obj>, std::function<bool(const Obj&, const Obj&)>> MYPQ;
	MYPQ pq([](const Obj& one, const Obj& two) -> bool {if (one.val_ > two.val_) { return true; } else { return false; }});

	for (size_t i = 0; i != vec.size(); ++i)
	{
		pq.push(vec[i]);
	}
	std::cout << "Minimum object: " << pq.top().val_ << std::endl;
	pq.pop();
	std::cout << "Minimum object: " << pq.top().val_ << std::endl;
	pq.pop();
}

void defaultPriority()
{
	std::priority_queue<int> pq;

	pq.push(4);
	pq.push(10);
	pq.push(102);
	pq.push(9);

	while (!pq.empty())
	{
		std::cout << pq.top() << std::endl;
		pq.pop();
	}
}

void greaterPriority()
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	pq.push(4);
	pq.push(10);
	pq.push(102);
	pq.push(9);

	while (!pq.empty())
	{
		std::cout << pq.top() << std::endl;
		pq.pop();
	}
}