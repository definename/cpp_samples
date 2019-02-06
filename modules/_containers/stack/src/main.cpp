#include "pch.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
	logger::InitializeLog("console");

	{
		Emulator::Stack<int> stack;
		for (int i = 0; i <= 10; ++i) {
			stack.Push(i);
		}

		if (!stack.Empty())
		{
			logger::log->info("Minimum value in stack: {}", stack.Min());
			logger::log->info("Top value in stack: {}", stack.Top());
		}

		Emulator::StackPrinter<int>(stack);
	}

	{
		Emulator::Queue<int> queue;
		for (int i = 0; i <= 10; ++i) {
			queue.Push(i);
		}

		if (!queue.Empty())
		{
			logger::log->info("Minimum value in queue: {}", queue.Min());
			logger::log->info("Front value in queue: {}", queue.Front());
		}

		Emulator::QueuePrinter<int>(queue);
	}

	logger::UninitializeLog();

	return 0;
}