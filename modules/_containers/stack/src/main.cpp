#include "pch.h"

////////////////////////////////////////////////////////////////////////////
// Design and develop stack container to find minimum value for const time.
//

namespace emulator
{

template<typename T>
class stack
{
public:
	void push(const T& value) {
		stack_.emplace(value, stack_.empty() ? value : std::min(value, stack_.top().second));
	}

	T& top() {
		return stack_.top().first;
	}

	T& min() {
		return stack_.top().second;
	}

	void pop() {
		stack_.pop();
	}

	bool empty() const {
		return stack_.empty();
	}

	void clear()
	{
		while (!stack_.empty())
		{
			const auto& temp = stack_.top();
			logger::log->info("{} : {}", temp.first, temp.second);
			stack_.pop();
		}
	}


private:
	std::stack<std::pair<T, T>> stack_;
};

}

int main()
{
	logger::InitializeLog("console");

	emulator::stack<int> coll;
	for (int i = 0; i <= 10; ++i) {
		coll.push(i); 
	}

	if (!coll.empty())
	{
		logger::log->info("Minimum value in stack: {}", coll.min());
		logger::log->info("Top value in stack: {}", coll.top());
	}
	coll.clear();

	logger::UninitializeLog();

	return 0;
}