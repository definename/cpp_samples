#ifndef PRINTER_H
#define PRINTER_H

////////////////////////////////////////////////////////////////////////////
// Design and develop stack container to find minimum value for const time.
//

namespace Emulator
{

template<typename T>
class Stack;

template<typename T>
void StackPrinter(Stack<T> stack)
{
	while (!stack.data_.empty())
	{
		const auto& temp = stack.data_.top();
		logger::log->info("{} : {}", temp.first, temp.second);
		stack.data_.pop();
	}
}

template<typename T>
class Queue;

template<typename T>
void QueuePrinter(Queue<T> queue)
{
	logger::log->info("Stack1");
	StackPrinter<T>(queue.stack1_);

	logger::log->info("Stack2");
	StackPrinter<T>(queue.stack2_);
}

} // namespace Emulator

#endif PRINTER_H