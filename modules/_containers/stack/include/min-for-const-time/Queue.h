#ifndef QUEUE_H
#define QUEUE_H

//////////////////////////////////////////////////////////////////////////////////
// Task:
// Design and develop queue container to find minimum value for const time.
// http://e-maxx.ru/algo/stacks_for_minima

#include "Stack.h"

namespace Emulator
{

template<typename T>
class Queue
{
	template<typename T>
	friend void QueuePrinter(Queue<T>);

public:
	bool Empty() const {
		return stack1_.Empty() && stack2_.Empty();
	}

	const T& Front()
	{
		if (stack2_.Empty())
		{
			while (!stack1_.Empty())
			{
				stack2_.Push(stack1_.Top());
				stack1_.Pop();
			}
		}
		return stack2_.Top();
	}

	const T& Min() const
	{
		if (stack1_.Empty() && !stack2_.Empty()) {
			return stack2_.Min();
		}
		else if (!stack1_.Empty() && stack2_.Empty()) {
			return stack1_.Min();
		}
		else {
			return std::min(stack1_.Min(), stack2_.Min());
		}
	}

	void Push(const T& value) {
		stack1_.Push(value);
	}

private:
	Stack<T> stack1_;
	Stack<T> stack2_;
};

} // namespace Emulator

#endif QUEUE_H