#include "pch.h"

thread_local unsigned int range = 1;

void Increase(unsigned int range, const std::string& funcName)
{
	++range;
	logger::log->info("{}: {}", funcName, range);
}

int main(int argc, char* argv[])
{
	logger::InitializeLog("console");
	try
	{
		std::thread a(Increase, range, "a"), b(Increase, range, "b");

		logger::log->info("main: {}", range);

		a.join();
		b.join();
	}
	catch (spdlog::spdlog_ex& e)
	{
		std::cerr << "spdlog error occurred: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		logger::log->error("Error occurred {}", e.what());
	}
	logger::UninitializeLog();

	return 0;
}