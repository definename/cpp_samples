#ifndef STACK_H
#define STACK_H

//////////////////////////////////////////////////////////////////////////////////
// Task:
// Design and develop stack container to find minimum value for const time.
// http://e-maxx.ru/algo/stacks_for_minima

#include "Printer.h"

namespace Emulator
{

template<typename T>
class Stack
{
	template<typename T>
	friend void StackPrinter(Stack<T>);

public:
	bool Empty() const {
		return data_.empty();
	}

	const T& Min() const {
		return data_.top().second;
	}

	void Pop() {
		data_.pop();
	}

	void Push(const T& value) {
		data_.emplace(value, data_.empty() ? value : std::min(value, data_.top().second));
	}

	const T& Top() const {
		return data_.top().first;
	}

private:
	std::stack<std::pair<T, T>> data_;
};

} // namespace Emulator

#endif