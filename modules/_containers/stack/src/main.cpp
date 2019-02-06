#include "pch.h"

////////////////////////////////////////////////////////////////////////////
// Design and develop stack container to find minimum value for const time.
//

namespace Emulator
{

template<typename T>
class Stack
{
	template<typename T>
	friend void Printer(Stack<T>);

public:
	void push(const T& value) {
		data_.emplace(value, data_.empty() ? value : std::min(value, data_.top().second));
	}

	T& top() {
		return data_.top().first;
	}

	T& min() {
		return data_.top().second;
	}

	void pop() {
		data_.pop();
	}

	bool empty() const {
		return data_.empty();
	}

private:
	std::stack<std::pair<T, T>> data_;
};

template<typename T>
void Printer(Stack<T> coll)
{
	while (!coll.data_.empty())
	{
		const auto& temp = coll.data_.top();
		logger::log->info("{} : {}", temp.first, temp.second);
		coll.data_.pop();
	}
}

} // namespace Emulator

int main()
{
	logger::InitializeLog("console");

	Emulator::Stack<int> coll;
	for (int i = 0; i <= 10; ++i) {
		coll.push(i);
	}

	if (!coll.empty())
	{
		logger::log->info("Minimum value in stack: {}", coll.min());
		logger::log->info("Top value in stack: {}", coll.top());
	}

	Emulator::Printer<int>(coll);

	logger::UninitializeLog();

	return 0;
}